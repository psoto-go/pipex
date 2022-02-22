/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:59:44 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/22 18:38:03 by psoto-go         ###   ########.fr       */
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

void	open_files(t_pipex *pipex, char **envp, char **argv)
{
	int	fd;
	int	fd2;

	fd = open(argv[1], O_RDONLY);
	fd2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0666);
	forks_settings(pipex, envp, argv, fd, fd2);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	inicialize(&pipex);
	parser(argc, argv, &pipex, envp);
	open_files(&pipex, envp, argv);
	ft_error(0, &pipex);
}
