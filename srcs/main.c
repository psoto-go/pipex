/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:59:44 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/26 10:00:25 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	fork_son(t_pipex *pipex, char **envp, int fd, char **argv)
{
	close(pipex->fd[READ_END]);
	dup2(fd, STDIN_FILENO);
	close(fd);
	dup2(pipex->fd[WRITE_END], STDOUT_FILENO);
	close(pipex->fd[WRITE_END]);
	split_comand(pipex, argv, 0);
	check_slash(pipex);
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
	check_slash(pipex);
	if (execve(pipex->path_comand, pipex->comand, envp) == -1)
		ft_error(6, pipex);
}

void	forks_settings(t_pipex *p, char **envp, char **argv)
{
	pid_t	pid1;
	int		status;
	int		fd1;
	int		fd2;

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	pipe(p->fd);
	pid1 = fork();
	if (pid1 < 0)
		ft_error(7, p);
	if (pid1 == 0)
		fork_son(p, envp, fd1, argv);
	pid1 = fork();
	if (pid1 < 0)
		ft_error(7, p);
	if (pid1 == 0)
		fork_son2(p, envp, fd2, argv);
	close(p->fd[WRITE_END]);
	close(p->fd[READ_END]);
	close(fd1);
	close(fd2);
	waitpid(pid1, &status, 0);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	inicialize(&pipex);
	parser(argc, argv, &pipex, envp);
	forks_settings(&pipex, envp, argv);
	ft_error(0, &pipex);
}
