/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:49:17 by liton             #+#    #+#             */
/*   Updated: 2016/11/08 17:51:29 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void		alocation(int n, int *div, int *size)
{
	*size = 2;
	*div = 1;
	if (n >= 0)
	{
		*size = 1;
		n = -n;
	}
	while (n / *div < -9)
	{
		*div = *div * 10;
		*size = *size + 1;
	}
}

char			*ft_itoa(int n)
{
	char		*str;
	int			i;
	int			div;
	int			size;

	i = 0;
	alocation(n, &div, &size);
	str = (char *)malloc(sizeof(char) * size + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[i] = '-';
		i = i + 1;
	}
	if (n >= 0)
		n = -n;
	while (div >= 1)
	{
		str[i] = -(n / div % 10) + '0';
		i = i + 1;
		div = div / 10;
	}
	str[i] = '\0';
	return (str);
}
