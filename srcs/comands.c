/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:36:55 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/23 20:07:20 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	split_comand(t_pipex *pipex, char **argv, int flag)
{
	if (flag == 0)
	{
		if (pipex->comand)
			free_comand(pipex);
		if (ft_strlen(argv[2]) > 0)
			pipex->comand = ft_split(argv[2], ' ');
		else if (ft_strlen(argv[2]) > 0)
			ft_error(5, pipex);
	}
	if (flag == 1)
	{
		// printf("%zu\n", ft_strlen(argv[3]));
		if (pipex->comand)
			free_comand(pipex);
		if (ft_strlen(argv[3]) > 0)
			pipex->comand = ft_split(argv[3], ' ');
		else if (ft_strlen(argv[3]) > 0)
			ft_error(5, pipex);
	}
}

void	check_commands(t_pipex *pipex, char **argv)
{
	split_comand(pipex, argv, 0);
	check_slash(pipex);
	split_comand(pipex, argv, 1);
	check_slash(pipex);
}
