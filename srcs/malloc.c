/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:56:37 by liton             #+#    #+#             */
/*   Updated: 2020/02/13 16:19:46 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include <unistd.h>

t_malloc g_malloc = {NULL, NULL, NULL};

t_page			*create_list(size_t size, void *ptr, int pos, int page)
{
	t_page		*new;

	new = (t_page*)ptr;
	new->next = NULL;
	ft_putstr("size add aloc = ");
	ft_putnbr(size);
	ft_putchar('\n');
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
	ft_putstr("add_alloc\n");
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
		ft_putstr("new_map\n");
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
	t_page		*tmp;

	if ((int)size < 0)
	{
		ft_putstr("SIZE == 0\n");
//		return (mmap(0, 0, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0));
		return (NULL);
	}
	while (size % 16 != 0)
		size++;
	ft_putstr("size : ");
	ft_putnbr(size);
	ft_putchar('\n');
	if (size <= TINY)
		return (check_page(size, &g_malloc.tiny, TINY_PAGE));
	else if (size <= SMALL)
	{
		tmp = check_page(size, &g_malloc.small, SMALL_PAGE);
		show_alloc_mem();
		return (tmp);
	}
	size += META;
	tmp = check_page(size, &g_malloc.large, size);
//	return (check_page(size, &g_malloc.large, size));
//	show_alloc_mem();
	return (tmp);
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
