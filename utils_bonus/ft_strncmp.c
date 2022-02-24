/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 11:08:44 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/24 10:55:42 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (n > j)
	{
		if (((unsigned char *)str1)[i] > ((unsigned char *)str2)[i])
			return (1);
		else if (((unsigned char *)str1)[i] < ((unsigned char *)str2)[i])
			return (-1);
		else if (!((unsigned char *)str1)[i] || !((unsigned char *)str2)[i])
			return (0);
		i++;
		j++;
	}
	return (0);
}
