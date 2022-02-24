/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psoto-go <psoto-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 09:46:25 by psoto-go          #+#    #+#             */
/*   Updated: 2022/02/24 10:53:58 by psoto-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static	int	count_words(char const *s, char c)
{
	int		wlen;
	int		i;
	size_t	w;

	i = 0;
	wlen = 0;
	w = 0;
	while (s[i])
	{
		if (!wlen && s[i] != c)
			w++;
		if (s[i] == c)
			wlen = 0;
		else
			wlen = 1;
		i++;
	}
	return (w);
}

static	int	len_word(char const *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] == c)
		i++;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

char	**rellena(char const *s, char **des, char c)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	while (++i < count_words(s, c))
	{
		k = 0;
		des[i] = malloc(sizeof(*s) * (len_word(&s[j], c) + 1));
		if (!(des[i]))
			des[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
		{
			des[i][k] = s[j];
			k++;
			j++;
		}
		des[i][k] = '\0';
	}
	des[i] = 0;
	return (des);
}

char	**ft_split(const char *s, char c)
{
	char	**str;

	if (!s)
		return (NULL);
	str = (char **)malloc(sizeof(*str) * (count_words(s, c) + 1));
	if (!(str))
		return (NULL);
	str = rellena(s, str, c);
	return (str);
}
