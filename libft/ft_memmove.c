/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:10:34 by liton             #+#    #+#             */
/*   Updated: 2016/11/08 13:51:57 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int		i;
	char	*tmp;
	char	*tmp2;

	tmp = (char*)dest;
	tmp2 = (char*)src;
	if (tmp2 < tmp)
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			tmp[i] = tmp2[i];
			i--;
		}
	}
	else if (tmp != tmp2)
	{
		i = -1;
		while (++i < (int)n)
			tmp[i] = tmp2[i];
	}
	return (dest);
}
