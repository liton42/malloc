/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/06 21:24:38 by liton             #+#    #+#             */
/*   Updated: 2017/01/23 02:11:47 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_split_atoi(const char *nptr, int stop, int i, int verif)
{
	int		convert;

	convert = 0;
	while (nptr[i] && stop == 1)
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			convert = convert * 10 + nptr[i] - 48;
		else if (!(nptr[i] >= '0' && nptr[i] <= '9'))
			stop = (nptr[verif] >= '0' && nptr[verif] <= '9') ? 2 : 0;
		i++;
	}
	return (convert);
}

int				ft_atoi(const char *nptr)
{
	int		convert;
	int		stop;
	int		i;
	int		bol;
	int		verif;

	convert = 0;
	stop = 1;
	i = 0;
	bol = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t' || nptr[i] == '\v' ||
			nptr[i] == '\f' || nptr[i] == '\r' || nptr[i] == '\n')
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i++] == '-')
			bol = 1;
	}
	verif = i;
	convert = ft_split_atoi(nptr, stop, i, verif);
	if (stop == 0)
		return (0);
	if (bol == 1)
		convert = -convert;
	return (convert);
}
