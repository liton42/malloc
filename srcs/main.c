/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:56:37 by liton             #+#    #+#             */
/*   Updated: 2019/03/29 18:47:07 by hakaishin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
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
	int			align;
	void		*ptr;
	t_page		*meta;
	t_page		*tmp;

	tmp = *page;
	while (tmp->next)
		tmp = tmp->next;
	ptr = (void*)tmp + META + tmp->size;;
	align = tmp->pos + META + tmp->size;
	while (align % 16 != 0)
	{
		align++;
		ptr++;
	}
	meta = create_list(size, ptr, align);
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
	t_page			*block;

	meta = NULL;
	if (!*page || size > SMALL || check_place(size, page, type) == 0)
	{
		if ((ptr = mmap(0, type, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
			return (NULL);
		meta = create_list(size, ptr, 0);
		return (add_page(&meta, page));
	}
	if ((block = find_block(size, page)) != NULL)
		return (block);
	return (add_alloc(size, page));
}

void				*malloc(size_t size)
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

void		strcopie(char **str, int n, char c)
{
	int		i;

	i = 0;
	while (i < n)
	{
		(*str)[i] = c;
		i++;
	}
	(*str)[i] = '\0';
}

int					main(void)
{
	char			*test;
	char			*lol;
	char			*oui;

	lol = (char*)malloc(sizeof(char) * 8);
	strcopie(&lol, 7, 'K');
	oui = (char*)malloc(sizeof(char) * 4);
	strcopie(&oui, 3, 'V');
	free(lol);
	test = (char*)malloc(sizeof(char) * 3);
	strcopie(&test, 2, 'X');
	print_memory(g_malloc.tiny, 16 * 20);
}
