/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <liton@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 02:10:16 by liton             #+#    #+#             */
/*   Updated: 2020/01/07 14:16:21 by hakaishin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include <unistd.h>

void			show_alloc_mem(void)
{
	void		*tmp;
	t_page 		*tiny;
	t_page		*small;
	t_page		*large;

	tiny = g_malloc.tiny;
	printf("TINY : %p\n", tiny);
	while (tiny)
	{
		tmp = (void*)tiny + META + tiny->size;
		printf("%p - %p : %zu octets\n", tiny + 1, tmp, tiny->size);
		tiny = tiny->next;
	}
	small = g_malloc.small;
	printf("SMALL : %p\n", small);
	while (small)
	{
		tmp = (void*)small + META + small->size;
		printf("%p - %p : %zu octets\n", small + 1, tmp, small->size);
		small = small->next;
	}
	large = g_malloc.large;
	printf("LARGE : %p\n", large);
	while (large)
	{
		tmp = (void*)large + META + large->size;
		printf("%p - %p : %zu octets\n", large + 1, tmp, large->size);
		large = large->next;
	}
}

int					check_place(size_t size, t_page **page, int type)
{
	t_page			*tmp;

	tmp = *page;
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->pos + size + META > (unsigned long)type)
		return (0);
	return (1);
}

void				separate_block(t_page **page, t_page **new)
{
	t_page 			*tmp;

	tmp = (*page)->next;
	(*page)->next = *new;
	(*new)->next = tmp;
}

t_page				*find_block(size_t size, t_page **page)
{
	int				p;
	void			*ptr;
	int				data;
	t_page			*tmp;
	t_page			*new;

	tmp = *page;
	while (tmp)
	{
		data = META + tmp->size;
		if (tmp->size == 0 && tmp->block_size - META >= size)
		{
			while (size % 16 != 0)
				size++;
			tmp->size = size;
			return (tmp + 1);
		}
		else if (tmp->size < tmp->block_size && tmp->block_size - data >= META + size)
		{
			ptr = (void*)tmp + META + tmp->size;
			p = tmp->pos + META + tmp->size;
			while (p % 16 != 0)
			{
				p++;
				ptr++;
			}
			if (tmp->next && p + META + size > (unsigned long)tmp->next->pos)
				break ;
			new = create_list(size, ptr, p);
			new->block_size = tmp->block_size - (tmp->size + META);
			tmp->block_size = tmp->size + META;
			separate_block(&tmp, &new);
			return (new + 1);
		}
		tmp = tmp->next;
	}
	return (NULL);
}

void	print_memory(const void *addr, size_t size)
{
	if (addr == NULL)
		return;
	size_t			i;
	size_t 			j;
	unsigned char	*p;
	char 			*str;

	str = "0123456789abcdef";
	p = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < 16 && i + j < size)
		{
			write(1, &str[(*(p + i + j)/16) % 16], 1);
			write(1, &str[*(p + i + j) % 16], 1);
			if (j % 2)
				write(1, " ", 1);
			j += 1;
		}
		while (j < 16)
		{
			write(1, "  ", 2);
			if (j % 2)
				write(1, " ", 1);
			j++;
		}
		j = 0;
		while (j < 16 && i + j < size)
		{
			if (*(p + i + j) >= 32 && *(p + i + j) < 127)
				write(1, p + i + j, 1);
			else
				write(1, ".", 1);
			j += 1;
		}
		write(1, "\n", 1);
		i += 16;
	}
	printf("-------------------------------\n");
}
