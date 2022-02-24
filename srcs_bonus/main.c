/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:59:44 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/24 19:29:15 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

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

// void	forks_settings(t_pipex *p, char **envp, char **argv)
// {
// 	pid_t	pid1;
// 	pid_t	pid2;
// 	int		status;
// 	int		fd1;
// 	int		fd2;

// 	fd1 = open(argv[1], O_RDONLY);
// 	fd2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0666);
// 	pipe(p->fd);
// 	pid1 = fork();
// 	if (pid1 < 0)
// 		return (perror("Fork: "));
// 	if (pid1 == 0)
// 		fork_son(p, envp, fd1, argv);
// 	waitpid(pid1, &status, 0);
// 	pid2 = fork();
// 	if (pid2 < 0)
// 		return (perror("Fork: "));
// 	if (pid2 == 0)
// 		fork_son2(p, envp, fd2, argv);
// 	close(p->fd[WRITE_END]);
// 	close(p->fd[READ_END]);
// 	close(fd1);
// 	close(fd2);
// 	waitpid(pid2, &status, 0);
// }

void	forks_settings(t_pipex *p, char **envp, char **argv)
{
	int		fd1;
	int		fd2;
	int		i;
	pid_t	pid;
	int		status;

	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	i = 0;
	pid = 0;
	while (i < ft_lstsize(p->list) && waitpid(pid, &status, 0))
	{
		pipe(p->fd);
		pid = fork();
		if (pid < 0)
			return (perror("Fork: "));
		if (pid == 0)
			printf("%d\n", pid);
		i++;
	}
	envp = 0;
	// close(fd1);
	// close(fd2);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;

	inicialize(&pipex);
	parser(argc, argv, &pipex, envp);
	ft_printlst(&pipex);
	forks_settings(&pipex, envp, argv);
	// // while(42);
	// ft_lstiter(pipex.list, free);
	while (1)
	{
		
	}
	ft_error(0, &pipex);
}

	// pipex.lenlst = ft_lstsize(pipex.list);
	// printf("%d", pipex.lenlst);