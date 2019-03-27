/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:49:37 by liton             #+#    #+#             */
/*   Updated: 2016/11/08 13:49:38 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*begin;
	t_list	*tmp;

	if (!alst || !del)
		return ;
	begin = *alst;
	tmp = (*alst)->next;
	while (tmp)
	{
		del(begin->content, begin->content_size);
		free(begin);
		begin = tmp;
		tmp = tmp->next;
	}
	del(begin->content, begin->content_size);
	free(begin);
	*alst = NULL;
}
