/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:36:55 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/22 18:38:33 by psoto-go         ###   ########.fr       */
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

void	check_commands(t_pipex *pipex, char **argv)
{
	split_comand(pipex, argv, 0);
	correct_path(pipex);
	split_comand(pipex, argv, 1);
	correct_path(pipex);
}
