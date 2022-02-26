/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:36:55 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/26 11:27:01 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	split_comand(t_pipex *pipex, char **argv, int flag)
{
	if (flag == 0)
	{
		if (!argv[2][0] || (ft_isalpha(argv[2][0]) == 0))
			ft_error(5, pipex);
		if (pipex->comand)
			free_comand(pipex);
		pipex->comand = ft_split(argv[2], ' ');
	}
	if (flag == 1)
	{
		if (!argv[3][0] || (ft_isalpha(argv[3][0]) == 0))
			ft_error(5, pipex);
		if (pipex->comand)
			free_comand(pipex);
		pipex->comand = ft_split(argv[3], ' ');
	}
}

void	check_commands(t_pipex *pipex, char **argv)
{
	split_comand(pipex, argv, 0);
	check_slash(pipex);
	split_comand(pipex, argv, 1);
	check_slash(pipex);
}
