/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:50:11 by liton             #+#    #+#             */
/*   Updated: 2016/11/15 17:07:03 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ptr;
	void	*tmptr;

	if ((ptr = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL || content_size == 0)
	{
		ptr->content = NULL;
		ptr->content_size = 0;
	}
	else
	{
		if ((tmptr = ft_memalloc(content_size)) == NULL)
			return (NULL);
		ft_memcpy(tmptr, content, content_size);
		ptr->content = tmptr;
		ptr->content_size = content_size;
	}
	ptr->next = NULL;
	return (ptr);
}
