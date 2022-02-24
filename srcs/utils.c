/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 10:40:47 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/24 10:42:21 by psoto-go         ###   ########.fr       */
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

char	*ft_strjoin(char const *s1, char const *s2)
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
	free((char *) s1);
	return (aux);
}

char	*ft_strdup(const char *src)
{
	char			*aux;
	size_t			len;

	len = ft_strlen(src) + 1;
	if (len == 1)
		return (NULL);
	aux = (char *)malloc(len * sizeof(char));
	if (aux == NULL)
		return (NULL);
	ft_memcpy(aux, src, len);
	return (aux);
}
