/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:50:48 by liton             #+#    #+#             */
/*   Updated: 2016/11/08 17:56:11 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		i;
	char		*tab;

	i = 0;
	tab = (char*)s;
	while (i < n)
	{
		if (tab[i] == (char)c)
			return (tab + i);
		i++;
	}
	return (NULL);
}
