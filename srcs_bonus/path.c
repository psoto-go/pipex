/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:32:13 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/24 12:38:18 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	split_path(t_pipex *pipex)
{
	if (!pipex->path)
		ft_error(4, pipex);
	pipex->path_split = ft_split(pipex->path, ':');
	if (!pipex->path_split)
		ft_error(4, pipex);
}

void	put_path_command(t_pipex *pipex, char **argv)
{
	char	*uno;

	if (argv[2][0] == '/' && argv[3][0] != '/')
		pipex->path = ft_strdup(argv[2]);
	else if (argv[2][0] == '/' && argv[3][0] == '/')
	{
		uno = ft_strjoinlks(argv[2], ":");
		pipex->path = ft_strjoin(uno, argv[3]);
	}
	else if (argv[2][0] != '/' && argv[3][0] == '/')
		pipex->path = ft_strdup(argv[3]);
	else
		ft_error(4, pipex);
	split_path(pipex);
}

void	get_path(char **envp, t_pipex *pipex, char **argv)
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
	else if (flag == 0)
		put_path_command(pipex, argv);
}
