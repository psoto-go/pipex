/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 15:50:21 by psoto-go          #+#    #+#             */
/*   Updated: 2022/03/01 16:25:24 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_printlst(t_pipex *pipex)
{
	t_list	*tmp;

	tmp = pipex->list;
	while (tmp)
	{
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
}

t_pipex	get_nodo(t_pipex *pipex, int i)
{
	t_pipex	aux;
	int		j;

	aux = *pipex;
	j = 0;
	while (j < i)
	{
		aux.list = aux.list->next;
		j++;
	}
	return (aux);
}

void	do_backups(t_pipex *p)
{
	p->bcstd[0] = dup(STDIN_FILENO);
	p->bcstd[1] = dup(STDOUT_FILENO);
}
