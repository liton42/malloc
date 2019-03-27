/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <livbrandon@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 02:11:51 by liton             #+#    #+#             */
/*   Updated: 2017/01/25 14:51:26 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long long int	ft_split_atoi(const char *nptr, int s, int i, int verif)
{
	long long int	convert;

	convert = 0;
	while (nptr[i] && s == 1)
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			convert = convert * 10 + nptr[i] - 48;
		else if (!(nptr[i] >= '0' && nptr[i] <= '9'))
			s = (nptr[verif] >= '0' && nptr[verif] <= '9') ? 2 : 0;
		i++;
	}
	return (convert);
}

long long int			ft_atoll(const char *nptr)
{
	long long int	convert;
	int				stop;
	int				i;
	int				bol;
	int				verif;

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
