/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaishin <liton@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 13:53:05 by hakaishin         #+#    #+#             */
/*   Updated: 2020/02/20 16:56:42 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

void		*calloc(size_t count, size_t size)
{
	void	*ptr;

//	ft_putendl("CALLOCCCCCCCCCCCCCCC");
//	ft_putnbr(count);
//	ft_putchar(' ');
//	ft_putnbr(size);
//	ft_putchar('\n');
	ptr = malloc(count * size);
	if (ptr)
		ft_bzero(ptr, count * size);
	return (ptr);
}
