/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:59:44 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/26 14:05:27 by psoto-go         ###   ########.fr       */
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

void	do_childs(t_pipex *pipex, int i, char **envp)
{
	pid_t	pid;
	int		status;

	pipe(pipex->fd);
	pid = fork();
	if (pid < 0)
		ft_error(7, pipex);
	if (pid > 0)
	{
		close(pipex->fd[WRITE_END]);
		dup2(pipex->fd[READ_END], STDIN_FILENO);
		waitpid(pid, &status, 0);
	}
	else
	{
		close(pipex->fd[READ_END]);
		dup2(pipex->fd[WRITE_END], STDOUT_FILENO);
		split_comand(pipex, get_nodo(pipex, i));
		check_slash(pipex);
		if (execve(pipex->path_comand, pipex->comand, envp) == -1)
			ft_error(6, pipex);
	}
}

void	forks_settings(t_pipex *p, char **envp, char **argv, int argc)
{
	int		fd1;
	int		fd2;
	int		i;

	i = 1;
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	dup2(fd1, STDIN_FILENO);
	dup2(fd2, STDOUT_FILENO);
	do_childs(p, 0, envp);
	while (i < ft_lstsize(p->list))
	{
		do_childs(p, i, envp);
		i++;
	}
	split_comand(p, get_nodo(p, i - 1));
	check_slash(p);
	if (execve(p->path_comand, p->comand, envp) == -1)
		ft_error(6, p);
	close(fd1);
	close(fd2);
	// p = 0;
	// argv = 0; 
	// argc = 0;
	// envp = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	inicialize(&pipex);
	parser(argc, argv, &pipex, envp);
	forks_settings(&pipex, envp, argv, argc);
	ft_error(0, &pipex);
}
