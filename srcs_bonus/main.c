/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:59:44 by psoto-go          #+#    #+#             */
/*   Updated: 2022/03/01 13:37:06 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

t_pipex	get_nodo(t_pipex *pipex, int i)
{
	t_pipex	aux;
	int		j;

	aux = *pipex;
	j = 0;
	while (j < i)
	{
		aux.list = aux.list->next;
		j++;
	}
	return (aux);
}

void	check_here_doc(t_pipex *pipex, char *argv)
{
	char *line;

	close(pipex->fd[READ_END]);
	write(STDOUT_FILENO, "> ", 2);
	line = get_next_line(STDIN_FILENO);
	while (line)
	{
		if (ft_strncmp(argv, line, ft_strlen(argv)) == 0)
		{
			close(pipex->fd[WRITE_END]);
			free(line);
			ft_error(0, pipex);
		}
		write(STDOUT_FILENO, "> ", 2);
		write(pipex->fd[WRITE_END], line, ft_strlen(line) + 1);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	close(pipex->fd[WRITE_END]);
	free(line);
}

void	do_childs_here(t_pipex *pipex, char *argv)
{
	pid_t	pid;
	int		status;

	if (pipe(pipex->fd) == -1)
		ft_error(8, pipex);
	pid = fork();
	if (pid < 0)
		ft_error(7, pipex);
	if (pid > 0)
	{
		close(pipex->fd[WRITE_END]);
		dup2(pipex->fd[READ_END], STDIN_FILENO);
		close(pipex->fd[READ_END]);
		waitpid(pid, &status, 0);
	}
	else
		check_here_doc(pipex, argv);
}


void	do_childs(t_pipex *pipex, int i, char **envp)
{
	pid_t	pid;
	int		status;

	if (pipe(pipex->fd) == -1)
		ft_error(8, pipex);
	pid = fork();
	if (pid < 0)
		ft_error(7, pipex);
	if (pid > 0)
	{
		close(pipex->fd[WRITE_END]);
		dup2(pipex->fd[READ_END], STDIN_FILENO);
		close(pipex->fd[READ_END]);
		waitpid(pid, &status, 0);
	}
	else
	{
		close(pipex->fd[READ_END]);
		dup2(pipex->fd[WRITE_END], STDOUT_FILENO);
		close(pipex->fd[WRITE_END]);
		split_comand(pipex, get_nodo(pipex, i));
		check_slash(pipex);
		if (execve(pipex->path_comand, pipex->comand, envp) == -1)
			ft_error(6, pipex);
	}
}

void	do_backups(t_pipex *p)
{
	p->bcstd[0] = dup(STDIN_FILENO);
	p->bcstd[1] = dup(STDOUT_FILENO);
}

void	forks_settings(t_pipex *p, char **envp, char **argv)
{
	int		i;

	do_backups(p);
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		do_childs_here(p, argv[2]);
	else
		dup2(p->fdstd[0], STDIN_FILENO);
	i = 0;
	while (i < ft_lstsize(p->list))
	{
		do_childs(p, i, envp);
		i++;
	}
	split_comand(p, get_nodo(p, i - 1));
	check_slash(p);
	dup2(p->fdstd[1], STDOUT_FILENO);
	close(p->fdstd[0]);
	close(p->fdstd[1]);
	if (execve(p->path_comand, p->comand, envp) == -1)
		ft_error(6, p);
	dup2(p->bcstd[0], STDIN_FILENO);
	dup2(p->bcstd[1], STDOUT_FILENO);
	close(p->bcstd[WRITE_END]);
	close(p->bcstd[READ_END]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	inicialize(&pipex);
	parser(argc, argv, &pipex, envp);
	// ft_printlst(&pipex);
	forks_settings(&pipex, envp, argv);
	ft_error(0, &pipex);
}
