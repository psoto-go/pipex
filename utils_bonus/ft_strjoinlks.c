/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinlks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 11:56:05 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/24 10:53:56 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_strjoinlks(char const *s1, char const *s2)
{
	char		*aux;
	size_t		count;
	size_t		i;
	size_t		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	aux = (char *)malloc(len + 1 * sizeof(char));
	if (!aux)
		return (NULL);
	count = 0;
	i = 0;
	while (count < len && s1[count])
	{
		aux[count] = s1[count];
		count++;
	}
	while (count < len && s2[i])
		aux[count++] = s2[i++];
	aux[count] = '\0';
	return (aux);
}
