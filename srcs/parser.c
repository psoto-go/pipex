/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 18:48:37 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/16 15:09:26 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	num_args(int argc)
{
	if (argc != 5)
		ft_error(1);
}

void	check_file(char *argv)
{
	int fd;
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		if (errno == 2)
			ft_error(2);
		else
			ft_error(3);
	}
	close(fd);
}

// void	check_command(char *argv)
// {

// }

void	parser(int argc, char **argv)
{
	// int i;
	// int j;

	// i = 0;
	// while (argv[i] != '\0')
	// {
	// 	j = 0;
	// 	while (argv[i][j] != '\0')
	// 	{
	// 		ft_printf("%c", argv[i][j]);
	// 		j++;
	// 	}
	// 	ft_printf("\n");
	// 	i++;
	// }
	num_args(argc);
	check_file(argv[1]);
	// if (argc != 5)
	// {
	// 	ft_printf("error");
	// 	exit(0);
	// }
}