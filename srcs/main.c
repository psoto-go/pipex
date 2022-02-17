/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:59:44 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/17 17:40:58 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	split_comand(t_pipex *pipex, char **argv)
{
	if (!pipex->comand)
		pipex->comand = ft_split(argv[2], ' ');
	else if (pipex->comand)
	{
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
	while ((envp[i] != '\0') && flag == 0)
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

void	fork_son(t_pipex *pipex)
{
	close(pipex->fd[READ_END]);
	dup2(pipex->fd[WRITE_END], STDOUT_FILENO);
	close(pipex->fd[WRITE_END]);
	printf("sa");
}

void	forks_settings(t_pipex *pipex)
{
	pid_t pid;
	
	pipe(pipex->fd);
	// printf("%d\n", getpid());
	pid = fork();
	// printf("%d\n", pid);
	if (pid == 0)
		fork_son(pipex);
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
	// parser(argc, argv, &pipex);
	argc = 0;
	get_path(envp, &pipex);
	split_comand(&pipex, argv);
	correct_path(&pipex);
	execve(pipex.path_comand, pipex.comand, &pipex.path);
	split_comand(&pipex, argv);
	correct_path(&pipex);
	execve(pipex.path_comand, pipex.comand, &pipex.path);
	// forks_settings(&pipex);
	ft_error(0, &pipex);
}
