/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 12:41:44 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/16 17:14:41 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	a(void)
{
	system("leaks pipex");
}

void	ft_error(int num)
{
	if (num == 1)
		ft_printf("%s", "Numero de argumentos invalido");
	else if (num == 2)
		perror("No ha sido posible abrir el archivo");
	else if (num == 3)
		perror("Error de lectura");
	else if (num == 4)
		perror("Error con el path");
	// atexit(a);
	exit(0);
}