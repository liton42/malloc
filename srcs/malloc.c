/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:56:37 by liton             #+#    #+#             */
/*   Updated: 2020/02/25 16:06:13 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include <unistd.h>
#include <stdlib.h>

t_malloc g_malloc = {NULL, NULL, NULL};
pthread_mutex_t		g_malloc_mutex = PTHREAD_MUTEX_INITIALIZER;

t_page			*create_list(size_t size, void *ptr, int pos, int page)
{
	t_page		*new;

	new = (t_page*)ptr;
	new->next = NULL;
	new->size = size;
	new->page = page;
	new->block_size = size + META;
	new->pos = pos;
	return (new);
}

t_page			*add_alloc(size_t size, t_page **page)
{
	int			align;
	void		*ptr;
	t_page		*meta;
	t_page		*tmp;

	tmp = *page;
	while (tmp->next)
		tmp = tmp->next;
	ptr = (void*)tmp + tmp->block_size;
	align = tmp->pos + tmp->block_size;
	meta = create_list(size, ptr, align, tmp->page);
	tmp->next = meta;
//	ft_putendl("ADD ALLOC");
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
	return (*meta + 1);
}

int					check(t_page **page)
{
	t_page			*tmp;

	tmp = *page;
	if (*page == NULL)
		return (1);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp->page + 1);
}

t_page				*check_page(size_t size, t_page **page, size_t type)
{
	int				p;
	void			*ptr;
	t_page			*meta;
	t_page			*block;

	meta = NULL;
	if (*page && (block = find_block(size, page)) != NULL)
		return (block);
	if (!*page || size > SMALL || check_place(size, page, type) == 0)
	{
		if ((ptr = mmap(0, type, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
			return (NULL);
		p = check(page);
		meta = create_list(size, ptr, 0, p);
		return (add_page(&meta, page));
	}
	return (add_alloc(size, page));
}

void				*malloc(size_t size)
{
	int			t;
	void		*tmp;

	if (size < 0)
		return (NULL);
	if (size == 0)
		size = 16;
	while (size % 16 != 0)
		size++;
	pthread_mutex_lock(&g_malloc_mutex);
	if (size <= TINY)
		tmp = check_page(size, &g_malloc.tiny, TINY_PAGE);
	else if (size <= SMALL)
		tmp = check_page(size, &g_malloc.small, SMALL_PAGE);
	else
	{
		t = size + META;
		while (t % 4096 != 0)
			t++;
		tmp = check_page(size, &g_malloc.large, t);
	}
	pthread_mutex_unlock(&g_malloc_mutex);
	return(tmp);
}
