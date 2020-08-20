/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaishin <liton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 02:18:36 by hakaishin         #+#    #+#             */
/*   Updated: 2020/02/25 17:16:00 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

int			check_add(void *ptr, t_page **page)
{
	t_page		*tmp;

	tmp = *page;
	while (tmp)
	{
		if (tmp + 1 == ptr)
		{
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
	if (check_add(ptr, &g_malloc.tiny))
		return;
	if (check_add(ptr, &g_malloc.small))
		return;
	if (check_add(ptr, &g_malloc.large))
		return;
}
