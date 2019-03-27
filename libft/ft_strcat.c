/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:10:42 by liton             #+#    #+#             */
/*   Updated: 2016/11/08 14:45:07 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t		dest_size;
	size_t		j;

	dest_size = ft_strlen(dest);
	j = -1;
	while (src[++j])
		dest[dest_size + j] = src[j];
	dest[dest_size + j] = '\0';
	return (dest);
}
