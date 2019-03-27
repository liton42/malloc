/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:57:03 by liton             #+#    #+#             */
/*   Updated: 2016/11/10 20:47:59 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int			nb_word(char const *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i] != '\0')
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static char			*place_word(char *tmp, char const *s, int begin, int lenght)
{
	int		i;

	i = 0;
	if (!(tmp = (char*)malloc(sizeof(char) * (lenght + 1))))
		return (NULL);
	while (i < lenght)
	{
		tmp[i] = s[begin];
		begin++;
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

static char			**size_word(char **tab, char const *s, char c)
{
	int		begin;
	int		i;
	char	*tmp;
	int		j;

	i = 0;
	j = 0;
	tmp = NULL;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			begin = i;
		while (s[i] && s[i] != c)
			i++;
		if (s[i] == c || (s[i] == '\0' && s[i - 1] != c))
		{
			tmp = place_word(tmp, s, begin, i - begin);
			tab[j] = tmp;
			j++;
		}
	}
	tab[j] = 0;
	return (tab);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**tab;

	tab = NULL;
	if (s)
	{
		if (!(tab = (char**)malloc(sizeof(char*) * (nb_word(s, c) + 1))))
			return (NULL);
		tab = size_word(tab, s, c);
	}
	return (tab);
}
