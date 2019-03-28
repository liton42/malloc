/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaishin <liton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:14:41 by hakaishin         #+#    #+#             */
/*   Updated: 2019/03/28 12:16:16 by hakaishin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_page			*search_alloc(void *ptr, size_t size, t_page **page, size_t t)
{
	unsigned long	pos;
	t_page			*tmp;

	tmp = *page;
	(void)t;
	while (tmp)
	{
		if ((void*)tmp + META == ptr)
		{
			if (tmp->size >= size)
			{
				printf("111111\n");
				return (tmp + 1);
			}
			pos = tmp->pos + META + (tmp->size - 1) + (size - tmp->size);
			if (tmp->next != NULL && (int)pos < tmp->next->pos)
			{
				printf("222222222\n");
				return (tmp + 1);
			}
			ft_memset(tmp + 1, '.', tmp->size);
			tmp->size = 0;
			printf("3333333333333\n");
			return (mmalloc(size));
		}
		tmp = tmp->next;
	}
	return (NULL);
}

t_page			*get_alloc(void *ptr, size_t size)
{
	t_page		*tmp;

	if ((tmp = search_alloc(ptr, size, &g_malloc.tiny, TINY)) != NULL)
		return (tmp);
	if ((tmp = search_alloc(ptr, size, &g_malloc.small, TINY)) != NULL)
		return (tmp);
	if ((tmp = search_alloc(ptr, size, &g_malloc.large, TINY)) != NULL)
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
		return (mmalloc(size));
	return (get_alloc(ptr, size));	
}
