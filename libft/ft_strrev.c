/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 13:01:31 by liton             #+#    #+#             */
/*   Updated: 2016/11/09 13:10:37 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strrev(char *s)
{
	char	*new_str;
	int		i;
	int		end_s;

	i = 0;
	end_s = ft_strlen(s) - 1;
	if (!(new_str = (char*)(malloc)(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (end_s >= 0)
	{
		new_str[i] = s[end_s];
		i++;
		end_s--;
	}
	new_str[i] = '\0';
	return (new_str);
}
