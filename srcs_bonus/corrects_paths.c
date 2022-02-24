/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   corrects_paths.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 16:45:01 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/24 12:50:52 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

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

void	correct_path_slash(t_pipex *pipex)
{
	int		i;
	int		flag;

	i = 0;
	flag = 0;
	if (access(pipex->comand[0], F_OK) == 0)
	{
		if (pipex->path_comand)
			free(pipex->path_comand);
		pipex->path_comand = ft_strdup(pipex->comand[0]);
		flag = 1;
	}
	if (flag == 0)
		ft_error(5, pipex);
}

void	check_slash(t_pipex *pipex)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (pipex->comand[0][i])
	{
		if (pipex->comand[0][i] == '/')
		{
			flag = 1;
			break ;
		}
		i++;
	}
	if (flag == 0)
		correct_path(pipex);
	if (flag == 1)
		correct_path_slash(pipex);
}
