/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:58:51 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/26 11:13:47 by psoto-go         ###   ########.fr       */
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
# include <errno.h>
# define READ_END 0
# define WRITE_END 1

typedef struct pipex
{
	char	*path;
	char	**path_split;
	char	*path_comand;
	char	**comand;
	int		fd[2];
}	t_pipex;

void	parser(int argc, char **argv, t_pipex *pipex, char **envp);

void	ft_error(int num, t_pipex *pipex);

void	free_comand(t_pipex *pipex);

void	free_split_path(t_pipex *pipex);

void	check_commands(t_pipex *pipex, char **argv);

void	get_path(char **envp, t_pipex *pipex, char **argv);

void	correct_path(t_pipex *pipex);

void	correct_path_slash(t_pipex *pipex);

void	split_path(t_pipex *pipex);

void	split_comand(t_pipex *pipex, char **argv, int flag);

void	inicialize(t_pipex *pipex);

void	check_slash(t_pipex *pipex);

char	*ft_strjoinlks(char const *s1, char const *s2);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strdup(const char *src);

char	**ft_split(const char *s, char c);

int		ft_strncmp(const char *str1, const char *str2, size_t n);

char	*ft_substr(char const *s, unsigned int start, size_t len);

size_t	ft_strlen(const char *s);

void	*ft_memcpy(void *str1, const void *str2, size_t n);

int		ft_isalpha(int c);

#endif
