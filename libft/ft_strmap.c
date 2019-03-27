/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:52:41 by liton             #+#    #+#             */
/*   Updated: 2016/11/08 14:53:00 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_string;
	int		i;

	i = 0;
	new_string = NULL;
	if (s && f)
	{
		if (!(new_string = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (NULL);
		while (s[i])
		{
			new_string[i] = f(s[i]);
			i++;
		}
		new_string[i] = '\0';
	}
	return (new_string);
}
