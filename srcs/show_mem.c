/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <liton@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/22 02:10:16 by liton             #+#    #+#             */
/*   Updated: 2020/02/20 17:43:21 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"
#include <unistd.h>

void	ft_puthex(unsigned long long hex, int pad, int up)
{
	int		i;
	int		r;
	char	str[17];
	char	*s;

	i = 16;
	ft_bzero(str, 17);
	while (--i >= 0)
	{
		r = (int)(hex % (unsigned long long)16);
		hex = hex / (unsigned long long)16;
		if (r <= 15)
		{
			if (r < 10)
				str[i] = 48 + r;
			else
				str[i] = (up ? 65 : 97) + (r % 10);
		}
	}
	s = str + (16 - pad);
	ft_putstr(s);
}

void			show_alloc_mem(void)
{
	void		*tmp;
	t_page 		*tiny;
	t_page		*small;
	t_page		*large;
	int		t;
	t =0;


	
	tiny = g_malloc.tiny;
	ft_putstr("TINY : ");
	ft_putstr("0x");
	ft_puthex((unsigned long)tiny, 9, 0);
	ft_putchar('\n');
	while (tiny)
	{
		t += tiny->block_size;
		tmp = (void*)tiny + tiny->block_size;
		ft_putstr("0x");
		ft_puthex((unsigned long)tiny + 1, 9, 0);
		ft_putstr(" - ");
		ft_putstr("0x");
		ft_puthex((unsigned long)tmp, 9, 0);
		ft_putstr(" : ");
		ft_putnbr(tiny->size);
		ft_putstr(" octects ");
		ft_putnbr(tiny->page);
		ft_putchar('\n');
		//		printf("%p - %p : %zu octets\n", tiny + 1, tmp, tiny->size);
		tiny = tiny->next;
	}

	small = g_malloc.small;
//	printf("SMALL : %p\n", small);
	ft_putstr("SMALL : ");
	ft_putstr("0x");
	ft_puthex((unsigned long)small, 9, 0);
	ft_putchar('\n');	
	while (small)
	{
		tmp = (void*)small + small->block_size;
		ft_putstr("0x");
		ft_puthex((unsigned long)small + 1, 9, 0);
		ft_putstr(" - ");
		ft_putstr("0x");
		ft_puthex((unsigned long)tmp, 9, 0);
		ft_putstr(" : ");
		ft_putnbr(small->size);
		ft_putstr(" octects\n");
//		printf("%p - %p : %zu octets\n", small + 1, tmp, small->size);
		small = small->next;
	}
	large = g_malloc.large;
//	printf("LARGE : %p\n", large);
	ft_putstr("LARGE : ");
	ft_putstr("0x");
	ft_puthex((unsigned long)large, 9, 0);
	ft_putchar('\n');
	while (large)
	{
		tmp = (void*)large + large->block_size;
		ft_putstr("0x");
		ft_puthex((unsigned long)large + 1, 9, 0);
		ft_putstr(" - ");
		ft_putstr("0x");
		ft_puthex((unsigned long)tmp, 9, 0);
		ft_putstr(" : ");
		ft_putnbr(large->size);
		ft_putstr(" octects\n");
//		printf("%p - %p : %zu octets\n", large + 1, tmp, large->size);
		large = large->next;
	}
}

int					check_place(size_t size, t_page **page, int type)
{
	t_page			*tmp;
	t_page			*begin;

	tmp = *page;
	begin = tmp;
	while (tmp->next)
		tmp = tmp->next;
	while (tmp->page != 1 && begin->page != tmp->page)
			begin = begin->next;
	if ((unsigned long)(((void*)tmp + tmp->block_size) + size + META) > (unsigned long)((void*)(begin) + type))
		return (0);
	return (1);
}

t_page		*find_block(size_t size, t_page **page)
{
	t_page		*tmp;

	tmp = *page;
	while (tmp)
	{
		if (tmp->size == 0 && tmp->block_size >= size + META)
		{
			tmp->size = size;
			return (tmp + 1);
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
