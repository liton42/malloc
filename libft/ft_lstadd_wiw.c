/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_wiw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:09:31 by liton             #+#    #+#             */
/*   Updated: 2016/11/16 12:15:33 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstadd_wiw(t_list **alst, t_list *right_add, t_list *add)
{
	t_list	*begin;
	t_list	*tmp;

	if (!(*alst || right_add || add))
		return (NULL);
	begin = *alst;
	while (*alst != right_add)
	{
		if (!(*alst)->next)
			return (NULL);
		*alst = (*alst)->next;
	}
	if ((*alst)->next)
	{
		tmp = (*alst)->next;
		(*alst)->next = add;
		add->next = tmp;
	}
	*alst = begin;
	return (*alst);
}
