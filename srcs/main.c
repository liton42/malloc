/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:56:37 by liton             #+#    #+#             */
/*   Updated: 2019/03/27 15:55:46 by hakaishin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"
#include <unistd.h>
#include <stdlib.h>

t_page			*create_list(size_t size, void *ptr, int pos)
{
	t_page		*new;

	new = (t_page*)ptr;
	new->next = NULL;
	new->prev = NULL;
	new->size = size;
	new->pos = pos;
	return (new);
}

t_page			*add_alloc(size_t size, t_page **page)
{
	void		*ptr;
	t_page		*meta;
	t_page		*tmp;

	tmp = *page;
	while (tmp->next)
		tmp = tmp->next;
	ptr = (void*)tmp + META + tmp->size;
	meta = create_list(size, ptr, tmp->pos + META + size);
	tmp->next = meta;
	meta->prev = tmp;
	return (meta + 1);
}

t_page				*add_page(t_page **meta, t_page **page)
{
	t_page			*tmp;

	tmp = *page;
	if (*page == NULL)
	{
		*page = *meta;
		return (*meta + 1);
	}
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = *meta;
	(*meta)->prev = tmp;
	return (*meta + 1);
}

t_page				*check_page(size_t size, t_page **page, int type)
{
	void			*ptr;
	t_page			*meta;

	meta = NULL;
	if (!*page || size > SMALL || check_place(size, page, type) == 0)
	{
		ptr = mmap(0, type, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
		meta = create_list(size, ptr, META + size);
		return (add_page(&meta, page));
	}
	return (add_alloc(size, page));
}

void				*mmalloc(size_t size)
{
	initialize_malloc();
	if (size == 0)
		return (NULL);
	if (size <= TINY)
		return (check_page(size, &g_malloc.tiny, TINY_PAGE));
	else if (size <= SMALL)
		return (check_page(size, &g_malloc.small, SMALL_PAGE));
	return (check_page(size, &g_malloc.large, size));
}

int					main(void)
{
	printf("%zu\n", sizeof(t_page));
}
