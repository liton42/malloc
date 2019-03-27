/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:56:44 by liton             #+#    #+#             */
/*   Updated: 2016/11/08 17:59:57 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;

	i = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	while (s[i] != c)
	{
		if (i == 0 && s[i] != c)
			return (NULL);
		i--;
	}
	return ((char*)s + i);
}
