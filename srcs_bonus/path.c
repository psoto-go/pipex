/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:32:13 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/22 18:32:56 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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
