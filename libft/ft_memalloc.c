/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:50:22 by liton             #+#    #+#             */
/*   Updated: 2016/11/08 18:05:12 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void	*new_mem;
	size_t	i;

	i = 0;
	new_mem = NULL;
	if (!(new_mem = (void*)malloc(sizeof(void) * (size))))
		return (NULL);
	ft_bzero(new_mem, (int)size);
	return (new_mem);
}
