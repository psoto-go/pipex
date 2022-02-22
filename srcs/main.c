/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:59:44 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/22 18:21:12 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	split_comand(t_pipex *pipex, char **argv, int flag)
{	
	if (flag == 0)
	{
		if (pipex->comand)
			free_comand(pipex);
		pipex->comand = ft_split(argv[2], ' ');
	}
	else if (flag == 1)
	{
		if (pipex->comand)
			free_comand(pipex);
		pipex->comand = ft_split(argv[3], ' ');
	}
}

void	correct_path(t_pipex *pipex)
{
	char	*uno;
	char	*dos;
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	while (pipex->path_split[i])
	{
		uno = ft_strjoinlks(pipex->path_split[i], "/");
		dos = ft_strjoin(uno, pipex->comand[0]);
		if (access(dos, F_OK) == 0)
		{
			if (pipex->path_comand)
				free(pipex->path_comand);
			pipex->path_comand = ft_strdup(dos);
			flag = 1;
		}
		free(dos);
		i++;
	}
	if (flag == 0)
		ft_error(5, pipex);
}

void	split_path(t_pipex *pipex)
{
	if (!pipex->path)
		ft_error(4, pipex);
	pipex->path_split = ft_split(pipex->path, ':');
	if (!pipex->path_split)
		ft_error(4, pipex);
}

void	get_path(char **envp, t_pipex *pipex)
{
	int		i;
	int		flag;
	char	*subst;

	i = 0;
	flag = 0;
	while ((envp[i] != (void *)0) && flag == 0)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			subst = ft_substr(envp[i], 5, ft_strlen(envp[i]));
			pipex->path = ft_strdup(subst);
			free(subst);
			flag = 1;
		}
		i++;
	}
	if (flag == 1)
		split_path(pipex);
	else
		ft_error(4, pipex);
}

void	fork_son(t_pipex *pipex, char **envp, int fd, char **argv)
{
	close(pipex->fd[READ_END]);
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(pipex->fd[WRITE_END], STDOUT_FILENO);
	close(pipex->fd[WRITE_END]);
	split_comand(pipex, argv,0);
	correct_path(pipex);
	if (execve(pipex->path_comand, pipex->comand, envp) == -1)
		ft_error(6, pipex);
}

void	fork_son2(t_pipex *pipex, char **envp, int fd2, char **argv)
{
	close(pipex->fd[WRITE_END]);
	dup2(fd2, STDOUT_FILENO);
	close(fd2);
	dup2(pipex->fd[READ_END], STDIN_FILENO);
	close(pipex->fd[READ_END]);
	split_comand(pipex, argv, 1);
	correct_path(pipex);
	if (execve(pipex->path_comand, pipex->comand, envp) == -1)
		ft_error(6, pipex);
}

void	forks_settings(t_pipex *p, char **envp, char **argv, int fd1, int fd2)
{
	pid_t	pid1;
	pid_t	pid2;
	int		status;
	
	pipe(p->fd);
	pid1 = fork();
	if (pid1 < 0)
        return (perror("Fork: "));
	if (pid1 == 0)
		fork_son(p, envp, fd1, argv);
	waitpid(pid1, &status, 0);
	pid2 = fork();
	if (pid2 < 0)
        return (perror("Fork: "));
	if (pid2 == 0)
		fork_son2(p, envp, fd2, argv);
	close(p->fd[WRITE_END]);
	close(p->fd[READ_END]);
	waitpid(pid2, &status, 0);
}

void	check_commands(t_pipex *pipex, char **argv)
{
	split_comand(pipex, argv, 0);
	correct_path(pipex);
	split_comand(pipex, argv, 1);
	correct_path(pipex);
}

void	open_files(t_pipex *pipex, char **envp, char **argv)
{
	int	fd;
	int	fd2;

	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0666);
	forks_settings(pipex, envp, argv, fd, fd2);
}

void	inicialize(t_pipex *pipex)
{
	pipex->comand = NULL;
	pipex->path = NULL;
	pipex->path_split = NULL;
	pipex->path_comand = NULL;
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	inicialize(&pipex);
	parser(argc, argv, &pipex);
	get_path(envp, &pipex);
	check_commands(&pipex, argv);
	open_files(&pipex, envp, argv);
	ft_error(0, &pipex);
}
