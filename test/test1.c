/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test0.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zadrien <zadrien@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 12:25:22 by zadrien           #+#    #+#             */
/*   Updated: 2019/11/27 19:34:13 by zadrien          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int main() {
	int		i;
	char	*addr;

	i = 0;
	while (i < 1024) {
		addr = (char*)malloc(1024);
		addr[0] = 42;
		i++;
	}

	return 0;
}
