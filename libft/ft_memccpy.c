/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:50:32 by liton             #+#    #+#             */
/*   Updated: 2016/11/09 14:33:22 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char*)dest;
	s = (unsigned char*)src;
	if (n)
	{
		while (i < n && s[i] != (unsigned char)c)
		{
			d[i] = s[i];
			i++;
		}
		if (s[i] == (unsigned char)c && i != n)
		{
			d[i] = s[i];
			return (&d[i + 1]);
		}
	}
	return (0);
}
