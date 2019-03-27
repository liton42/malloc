/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaishin <liton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 02:18:36 by hakaishin         #+#    #+#             */
/*   Updated: 2019/03/27 07:25:22 by hakaishin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int			check_add(void *ptr, t_page *tmp)
{
	while (tmp)
	{
		if ((void*)tmp + META == ptr)
		{
			tmp->size = 1;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

void			mfree(void *ptr)
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
