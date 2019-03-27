/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:51:31 by liton             #+#    #+#             */
/*   Updated: 2016/11/08 13:51:32 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*tmp;
	char		*tmp2;

	i = 0;
	tmp = (char*)dest;
	tmp2 = (char*)src;
	while (i < n)
	{
		if (tmp2[i] == '\0')
			tmp[i] = '\0';
		else
			tmp[i] = tmp2[i];
		i++;
	}
	return (dest);
}
