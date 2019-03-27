/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:10:46 by liton             #+#    #+#             */
/*   Updated: 2017/02/09 16:19:57 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	free_join(char *s1, char *s2, int f)
{
	if (f == 1)
		free(s1);
	else if (f == 2)
		free(s2);
	else if (f == 3)
	{
		free(s1);
		free(s2);
	}
}

char	*ft_strjoinfree(char *s1, char *s2, int f)
{
	char	*new_str;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(new_str = (char*)(malloc)(sizeof(char) *
					ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[++i])
		new_str[i] = s1[i];
	while (s2[++j])
	{
		new_str[i] = s2[j];
		i++;
	}
	new_str[i] = '\0';
	free_join(s1, s2, f);
	return (new_str);
}
