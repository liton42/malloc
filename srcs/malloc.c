/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:56:37 by liton             #+#    #+#             */
/*   Updated: 2020/01/07 16:59:36 by hakaishin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

t_malloc g_malloc = {NULL, NULL, NULL};

t_page			*create_list(size_t size, void *ptr, int pos)
{
	t_page		*new;

	new = (t_page*)ptr;
	new->next = NULL;
	new->size = size;
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
	ptr = (void*)tmp + META + tmp->size;;
	align = tmp->pos + META + tmp->size;
	meta = create_list(size, ptr, align);
	tmp->next = meta;
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

t_page				*check_page(size_t size, t_page **page, size_t type)
{
	void			*ptr;
	t_page			*meta;
	t_page			*block;

	meta = NULL;
	if (page && (block = find_block(size, page)) != NULL)
		return (block);
	if (!*page || size > type || check_place(size, page, type) == 0)
	{
		if ((ptr = mmap(0, type, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)) == MAP_FAILED)
			return (NULL);
		meta = create_list(size, ptr, 0);
		return (add_page(&meta, page));
	}
	return (add_alloc(size, page));
}

void				*malloc(size_t size)
{
	if (size == 0)
		return (NULL);
	while (size % 16 != 0)
		size++;
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
	char		*t;
	char		*v;
	char		*o;
	char		*u;
	char		*z;
	char		*b;
	char		*e;

	t = (char*)malloc(sizeof(char) * 5);
	strcopie(&t, 4, 'C');
	v = (char*)malloc(sizeof(char) * 16);
	strcopie(&v, 15, 'D');
	o = (char*)malloc(sizeof(char) * 253);
	strcopie(&o, 252, 'E');
	u= (char*)malloc(sizeof(char) * 253);
	strcopie(&u, 252, 'F');
	free(o);
	z= (char*)malloc(sizeof(char) * 13);
	strcopie(&z, 12, 'R');
	b= (char*)malloc(sizeof(char) * 19);
	strcopie(&b, 18, 'W');
	e= (char*)malloc(sizeof(char) * 120);
	strcopie(&e, 119, 'U');
	print_memory(g_malloc.tiny, 16 * 60);
	while (g_malloc.tiny)
	{
		printf("size = %zu\n", g_malloc.tiny->size);
		printf("block_size = %zu\n", g_malloc.tiny->block_size);
		g_malloc.tiny = g_malloc.tiny->next;
	}
}

