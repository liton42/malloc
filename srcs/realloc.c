/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaishin <liton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 11:14:41 by hakaishin         #+#    #+#             */
/*   Updated: 2020/02/20 16:56:12 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_page			*search_alloc(void *ptr, size_t size, t_page **page)
{
	t_page			*cpy;
	t_page			*tmp;

	tmp = *page;
	while (tmp)
	{
		if ((void*)tmp + META == ptr)
		{
//			ft_putstr("REALLOC ");
//			ft_putnbr(tmp->size);
//			ft_putchar(' ');
//			ft_putnbr(size);
//			ft_putchar('\n');
			if (size > tmp->size || size < tmp->size)
			{
				pthread_mutex_unlock(&g_malloc_mutex);
				if (!(cpy = malloc(size)))
					return (NULL);
				if (size > tmp->size)
					ft_memcpy(cpy, tmp + 1, tmp->size);
				else
				{
					while (size % 16 != 0)
						size++;
					ft_memcpy(cpy, tmp + 1, size);
				}
				tmp->size = 0;
				return (cpy);	
			}
			else if (size == tmp->size)
				return (ptr);
			/*
			if (tmp->block_size - META >= size)
				return (tmp + 1);
			else if (tmp->block_size - META < size)
			{
				pthread_mutex_unlock(&g_malloc_mutex);
				if (!(cpy = malloc(size)))
					return (NULL);	
				ft_memcpy(cpy, tmp + 1, tmp->size);
				tmp->size = 0;
				return (cpy);
			}
			*/
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
	else if ((tmp = search_alloc(ptr, size, &g_malloc.small)) != NULL)
		return (tmp);
	else if ((tmp = search_alloc(ptr, size, &g_malloc.large)) != NULL)
		return (tmp);
	return (NULL);
}

void			*realloc(void *ptr, size_t size)
{
	void		*tmp;

	if (ptr == NULL)
		return (malloc(size));
	if (ptr != NULL && size == 0)
		return (malloc(size));
	pthread_mutex_lock(&g_malloc_mutex);
	tmp = get_alloc(ptr, size);
	pthread_mutex_unlock(&g_malloc_mutex);
	return (tmp);
}
