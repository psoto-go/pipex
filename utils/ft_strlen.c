/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 10:22:00 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/24 10:54:09 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}
