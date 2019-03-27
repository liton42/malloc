/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:53:41 by liton             #+#    #+#             */
/*   Updated: 2016/11/08 14:53:51 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t		dest_size;
	size_t		i;

	i = -1;
	dest_size = ft_strlen(dest);
	while (src[++i] && i < n)
		dest[dest_size + i] = src[i];
	dest[dest_size + i] = '\0';
	return (dest);
}
