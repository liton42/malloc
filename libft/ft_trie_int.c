/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trie_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:33:43 by liton             #+#    #+#             */
/*   Updated: 2016/11/09 14:56:46 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_trie_int(int *tab, int n)
{
	int		i;
	int		disorder;

	disorder = 0;
	while (disorder == 0)
	{
		i = 0;
		disorder = 1;
		while (i < n)
		{
			if (tab[i] > tab[i + 1])
			{
				ft_swap(&tab[i], &tab[i + 1]);
				disorder = 0;
			}
			i++;
		}
	}
}
