/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaishin <liton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 02:18:36 by hakaishin         #+#    #+#             */
/*   Updated: 2019/12/30 14:34:00 by hakaishin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

int			check_add(void *ptr, t_page *tmp)
{
	while (tmp)
	{
		if ((void*)tmp + META == ptr)
		{
			ft_memset(tmp + 1, 0, tmp->size);
			tmp->size = 0;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void			free(void *ptr)
{
	t_page		*tmp;

	if (ptr == NULL)
		return;
	tmp = g_malloc.tiny;
	if (check_add(ptr, tmp))
		return;
	tmp = g_malloc.small;
	if (check_add(ptr, tmp))
		return;
	tmp = g_malloc.large;
	if (check_add(ptr, tmp))
		return;
}
