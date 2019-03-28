/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:55:41 by liton             #+#    #+#             */
/*   Updated: 2019/03/28 12:12:54 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MALLOC_H
# define MALLOC_H

# include <stdio.h>
# include "libft.h"
# include <sys/mman.h>

# define META sizeof(t_page)
# define TINY 254
# define TINY_PAGE ((TINY + META) * 100) + 72
# define SMALL 1524
# define SMALL_PAGE ((SMALL + META) * 100) + 48
# define LARGE 4000
# define LARGE_PAGE ((LARGE + META) * 100)

typedef struct			s_page
{
	size_t				size;
	int					pos;
	struct s_page		*next;
	struct s_page		*prev;
}						t_page;


typedef	struct			s_malloc
{
	struct s_page		*tiny;
	struct s_page		*small;
	struct s_page		*large;
}						t_malloc;

void					show_alloc_mem(void);
void					initialize_malloc(void);
int						check_place(size_t size, t_page **page, int type);
void					print_memory(const void *addr, size_t size);
void					mfree(void *ptr);
void					*realloc(void *ptr, size_t size);
void					*mmalloc(size_t size);
t_malloc				g_malloc;
#endif
