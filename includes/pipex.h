/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:58:51 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/16 20:33:08 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <fcntl.h>
# include <unistd.h>
# include "../libft/libft.h"
# include <errno.h>

typedef struct pipex
{
	char	*path;
	char	**path_split;
	char	*path_comand;
	char	**comand;
}	t_pipex;

void	parser(int argc, char **argv, t_pipex *pipex);

void	ft_error(int num, t_pipex *pipex);

void	free_comand(t_pipex *pipex);

#endif
