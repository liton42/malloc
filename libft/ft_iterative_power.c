/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <livbrandon@outlook.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 03:11:58 by liton             #+#    #+#             */
/*   Updated: 2017/01/13 03:34:38 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int		ft_iterative_power(long int nb, int power)
{
	long int	nbr;

	nbr = nb;
	if (power == 0)
		return (1);
	while (power > 1)
	{
		nb /= nbr;
		--power;
	}
	return (nb);
}
