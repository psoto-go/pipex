/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 12:58:51 by psoto-go          #+#    #+#             */
/*   Updated: 2022/03/01 16:25:42 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

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
# define BUFFER_SIZE 1

typedef struct list
{
	void		*content;
	struct list	*next;
}	t_list;

typedef struct pipex
{
	char	*path;
	char	**path_split;
	char	*path_comand;
	char	**comand;
	int		fd[2];
	int		bcstd[2];
	int		fdstd[2];
	t_list	*list;
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

void	split_comand(t_pipex *pipex, t_pipex aux);

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

void	ft_lstadd_back(t_list **lst, t_list *new);

void	ft_lstclear(t_list **lst, void (*del)(void*));

t_list	*ft_lstlast(t_list *lst);

void	ft_lstdelone(t_list *lst, void (*del)(void*));

void	ft_lstiter(t_list *lst, void (*f)(void *));

void	ft_printlst(t_pipex *pipex);

void	check_only_command(char *argv, t_pipex *pipex);

t_list	*new_nodo(void *str, size_t size);

int		ft_lstsize(t_list *lst);

int		ft_isalpha(int c);

char	*get_next_line(int fd);

t_pipex	get_nodo(t_pipex *pipex, int i);

void	do_backups(t_pipex *p);

#endif
