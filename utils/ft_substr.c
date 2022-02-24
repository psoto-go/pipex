/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 11:38:59 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/24 10:56:14 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*aux;
	unsigned int	count;

	if (!s)
		return (NULL);
	if (len > ft_strlen(s))
		aux = (char *)malloc((ft_strlen(s)) * sizeof(char));
	else
		aux = (char *)malloc((len + 1) * sizeof(char));
	count = 0;
	if (!aux)
		return (NULL);
	if (start >= ft_strlen(s))
		start = ft_strlen(s);
	i = start;
	while (count < (unsigned int)len && s[i])
	{
		aux[count] = s[i];
		count++;
		i++;
	}
	aux[count] = '\0';
	return (aux);
}
