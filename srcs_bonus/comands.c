/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comands.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 18:36:55 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/26 13:35:35 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

t_list	*new_nodo(void *str, size_t size)
{
	t_list	*tmp;
	void	*con;

	tmp = malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	con = malloc(size);
	if (!con)
	{
		free(tmp);
		tmp = NULL;
	}
	ft_memcpy(con, str, size);
	tmp->content = con;
	tmp->next = NULL;
	return (tmp);
}

void	check_only_command(char *argv, t_pipex *pipex)
{
	if (!argv[0])
		ft_error(5, pipex);
	if (pipex->comand)
		free_comand(pipex);
	pipex->comand = ft_split(argv, ' ');
	check_slash(pipex);
}

void	split_comand(t_pipex *pipex, t_pipex aux)
{
	if (pipex->comand)
		free_comand(pipex);
	pipex->comand = ft_split(aux.list->content, ' ');
}
