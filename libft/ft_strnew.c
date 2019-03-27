/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:55:37 by liton             #+#    #+#             */
/*   Updated: 2016/11/08 14:56:01 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strnew(size_t size)
{
	char		*new_string;
	size_t		i;

	i = -1;
	if (!(new_string = (char*)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (++i < size)
		new_string[i] = '\0';
	new_string[i] = '\0';
	return (new_string);
}
