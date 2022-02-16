/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:59:44 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/16 17:15:11 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ab(void)
{
	system("leaks pipex");
}

void	split_path(t_pipex *pipex)
{
	int i;
	
	if (!pipex->path)
		ft_error(4);
	pipex->path_split = ft_split(pipex->path, ':');
	if (!pipex->path_split)
		ft_error(4);
	i = 0;
	while (pipex->path_split[i])
	{
		printf("%s\n", pipex->path_split[i]);
		i++;
	}
	
}

void	get_path(char **envp, t_pipex *pipex)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while ((envp[i] != '\0') && flag == 0)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			pipex->path = ft_strdup(envp[i]);
			flag = 1;
		}
		i++;
	}
	if (flag == 1)
		split_path(pipex);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex pipex;
	
	get_path(envp, &pipex);
	// printf("%s", pipex.path);
	parser(argc, argv);
	// atexit(ab);

	// printf("%d", getpid());
}






