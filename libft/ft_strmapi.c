/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:53:07 by liton             #+#    #+#             */
/*   Updated: 2016/11/08 14:53:28 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char				*new_string;
	unsigned int		i;

	i = 0;
	new_string = NULL;
	if (s && f)
	{
		if (!(new_string = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (NULL);
		while (s[i])
		{
			new_string[i] = f(i, s[i]);
			i++;
		}
		new_string[i] = '\0';
	}
	return (new_string);
}
