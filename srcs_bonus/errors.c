/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:41:44 by psoto-go          #+#    #+#             */
/*   Updated: 2022/03/01 17:09:56 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	free_comand(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->comand[i])
	{
		free(pipex->comand[i]);
		i++;
	}
	free(pipex->comand);
}

void	free_split_path(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (pipex->path_split[i])
	{
		free(pipex->path_split[i]);
		i++;
	}
	free(pipex->path_split);
}

void	ft_exit(t_pipex *pipex)
{
	if (pipex->list)
		ft_lstclear(&pipex->list, free);
	if (pipex->comand)
		free_comand(pipex);
	if (pipex->path_split)
		free_split_path(pipex);
	if (pipex->path)
		free(pipex->path);
	if (pipex->path_comand)
		free(pipex->path_comand);
	if (pipex->fd[WRITE_END])
		close(pipex->fd[WRITE_END]);
	if (pipex->fd[READ_END])
		close(pipex->fd[READ_END]);
	if (pipex->fd[READ_END])
		close(pipex->fdstd[READ_END]);
	if (pipex->fd[WRITE_END])
		close(pipex->fdstd[WRITE_END]);
	exit(0);
}

void	inicialize(t_pipex *pipex)
{
	pipex->comand = NULL;
	pipex->path = NULL;
	pipex->path_split = NULL;
	pipex->path_comand = NULL;
	pipex->list = NULL;
}

void	ft_error(int num, t_pipex *pipex)
{
	if (num == 1)
		printf("%s", "Numero de argumentos invalido\n");
	else if (num == 2)
		perror("No ha sido posible abrir el archivo");
	else if (num == 3)
		perror("Error de lectura");
	else if (num == 4)
		perror("Error con el path");
	else if (num == 5)
		perror("Comando no encontrado");
	else if (num == 6)
		perror("Error execve");
	else if (num == 7)
		perror("Error de fork");
	else if (num == 8)
		perror("Error de pipe");
	ft_exit(pipex);
}
