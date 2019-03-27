/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:54:20 by liton             #+#    #+#             */
/*   Updated: 2016/11/08 14:54:30 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t		i;

	i = -1;
	while (src[++i] && i < n)
		dest[i] = src[i];
	i--;
	while (++i < n)
		dest[i] = '\0';
	return (dest);
}
