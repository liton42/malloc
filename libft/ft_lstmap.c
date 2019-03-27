/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:50:01 by liton             #+#    #+#             */
/*   Updated: 2016/11/08 16:05:39 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*begin;
	t_list	*new;
	t_list	*new2;

	tmp = lst;
	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new = f(tmp);
	begin = new;
	tmp = tmp->next;
	while (tmp)
	{
		if (!(new2 = (t_list*)malloc(sizeof(t_list))))
			return (NULL);
		new2 = f(tmp);
		new->next = new2;
		new = new2;
		tmp = tmp->next;
	}
	return (begin);
}
