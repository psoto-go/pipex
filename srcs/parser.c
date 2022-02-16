/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:48:37 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/16 17:49:42 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	num_args(int argc, t_pipex *pipex)
{
	if (argc != 5)
		ft_error(1, pipex);
}

void	check_file(char *argv, t_pipex *pipex)
{
	int	fd;

	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		if (errno == 2)
			ft_error(2, pipex);
		else
			ft_error(3, pipex);
	}
	close(fd);
}

// void	check_command(char *argv)
// {

// }

void	parser(int argc, char **argv, t_pipex *pipex)
{
	num_args(argc, pipex);
	check_file(argv[1], pipex);
}
