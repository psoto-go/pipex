/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:41:44 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/17 11:37:28 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	a(void)
{
	system("leaks pipex");
}

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
	if (pipex->path)
		free(pipex->path);
	if (pipex->path_split)
		free_split_path(pipex);
	if (pipex->path_comand)
		free(pipex->path_comand);
	if (pipex->comand)
		free_comand(pipex);
	// atexit(a);
	exit(0);
}

void	ft_error(int num, t_pipex *pipex)
{
	if (num == 1)
		ft_printf("%s", "Numero de argumentos invalido");
	else if (num == 2)
		perror("No ha sido posible abrir el archivo");
	else if (num == 3)
		perror("Error de lectura");
	else if (num == 4)
		perror("Error con el path");
	else if (num == 5)
		perror("Comando no encontrado");
	ft_exit(pipex);
}
