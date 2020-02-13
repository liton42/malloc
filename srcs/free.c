/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaishin <liton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 02:18:36 by hakaishin         #+#    #+#             */
/*   Updated: 2020/02/13 15:44:32 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/malloc.h"

int			check_add(void *ptr, t_page **page)
{
	t_page		*tmp;

	tmp = *page;
	while (tmp)
	{
		if (tmp + 1 == ptr)
		{
//			ft_memset(tmp + 1, 0, tmp->block_size - META);
			ft_putstr("FREEE ");
			ft_putnbr((tmp)->size);
			ft_putchar('\n');
			(tmp)->size = 0;
			ft_putendl("BEGIN` FREE");
		//	show_alloc_mem();
			printf("ADRESSD = %p\n", tmp + 1);
			ft_putendl("END FREE");
			return (1);
		}
		tmp = (tmp)->next;
	}
	return (0);
}

void			free(void *ptr)
{
	t_page		*tmp;

	if (ptr == NULL)
		return;
	if (check_add(ptr, &g_malloc.tiny))
		return;
	if (check_add(ptr, &g_malloc.small))
		return;
	if (check_add(ptr, &g_malloc.large))
		return;
}
