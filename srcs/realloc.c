/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaishin <liton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:14:41 by hakaishin         #+#    #+#             */
/*   Updated: 2019/03/29 09:31:21 by hakaishin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_page			*search_alloc(void *ptr, size_t size, t_page **page)
{
	unsigned long	pos;
	t_page			*tmp;

	tmp = *page;
	while (tmp)
	{
		if ((void*)tmp + META == ptr)
		{
			if (tmp->size >= size)
				return (tmp + 1);
			pos = tmp->pos + META + (tmp->size - 1) + (size - tmp->size);
			if (tmp->next != NULL && (int)pos < tmp->next->pos)
				return (tmp + 1);
			ft_memset(tmp + 1, '.', tmp->size);
			tmp->size = 0;
			return (malloc(size));
		}
		tmp = tmp->next;
	}
	return (NULL);
}

t_page			*get_alloc(void *ptr, size_t size)
{
	t_page		*tmp;

	if ((tmp = search_alloc(ptr, size, &g_malloc.tiny)) != NULL)
		return (tmp);
	if ((tmp = search_alloc(ptr, size, &g_malloc.small)) != NULL)
		return (tmp);
	if ((tmp = search_alloc(ptr, size, &g_malloc.large)) != NULL)
		return (tmp);
	return (ptr);
}

void			*realloc(void *ptr, size_t size)
{
	if (ptr == NULL && size == 0)
		return (NULL);
	if (ptr != NULL && size == 0)
		return (ptr);
	if (ptr == NULL)
		return (malloc(size));
	return (get_alloc(ptr, size));	
}
