/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:58:25 by liton             #+#    #+#             */
/*   Updated: 2016/11/08 14:58:41 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*new_str;

	i = 0;
	new_str = NULL;
	if (s)
	{
		if (!(new_str = (char*)malloc(sizeof(char) * (len + 1))))
			return (NULL);
		while (s[i] && i < len)
		{
			new_str[i] = s[i + start];
			i++;
		}
		new_str[i] = '\0';
	}
	return (new_str);
}
