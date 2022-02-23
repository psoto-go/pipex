/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:48:37 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/23 19:20:33 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	num_args(int argc, t_pipex *pipex)
{
	if (argc != 5)
		ft_error(1, pipex);
}

void	check_file(char **argv, t_pipex *pipex)
{
	int	fd;
	int	fd2;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		if (errno == 2)
			ft_error(2, pipex);
		else
			ft_error(3, pipex);
	}
	fd2 = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0666);
	if (fd2 < 0)
	{
		if (errno == 2)
			ft_error(2, pipex);
		else
			ft_error(3, pipex);
	}
	close(fd);
	close(fd2);
}

void	parser(int argc, char **argv, t_pipex *pipex, char **envp)
{
	num_args(argc, pipex);
	check_file(argv, pipex);
	get_path(envp, pipex, argv);
	check_commands(pipex, argv);
}
