/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:57:43 by liton             #+#    #+#             */
/*   Updated: 2017/01/13 23:56:51 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int		i;
	int		j;
	int		tmp;

	i = 0;
	j = 0;
	if (!(big[0] || little[0]))
		return ((char*)big);
	while (big[i])
	{
		tmp = i;
		while (big[i] && little[j] && big[i] == little[j])
		{
			i++;
			j++;
		}
		if (!little[j])
			return ((char*)big + tmp);
		else
			i = tmp;
		j = 0;
		i++;
	}
	return (NULL);
}
