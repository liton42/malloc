/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liton <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 17:06:21 by liton             #+#    #+#             */
/*   Updated: 2017/02/17 02:10:10 by liton            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

t_gnl	*create_chained_list(t_gnl *list, const int fd)
{
	t_gnl	*new;

	if (!(new = (t_gnl*)malloc(sizeof(t_gnl))))
		return (NULL);
	new->fd = fd;
	new->save = ft_strnew(0);
	new->close = 0;
	new->end = 0;
	new->prev = NULL;
	new->next = NULL;
	if (!list)
		return (new);
	list->next = new;
	new->prev = list;
	list = new;
	return (list);
}

t_gnl	*copy(t_gnl *list, char **line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (list->save[i] != '\n' && list->save[i])
		i++;
	*line = ft_strsub(list->save, 0, i);
	tmp = ft_strdup(list->save);
	free(list->save);
	if (tmp[i])
		list->save = ft_strsub(tmp, i + 1, ft_strlen(tmp + (i + 1)));
	else
		list->end = 1;
	free(tmp);
	return (list);
}

int		read_fd(char **line, t_gnl **list, const int fd)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;

	while ((ret = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		(*list)->save = ft_strjoinfree((*list)->save, buff, 1);
		if ((ft_strchr(buff, '\n') || ret < BUFF_SIZE))
		{
			*list = copy(*list, line);
			return (1);
		}
	}
	if (ret == -1)
		++(*list)->close;
	return (0);
}

int		fd_in_list(const int fd, char **line, t_gnl **list)
{
	while (*list && (*list)->prev && (*list)->fd != fd)
		*list = (*list)->prev;
	while (*list && (*list)->next && (*list)->fd != fd)
		*list = (*list)->next;
	if ((!*list) || (*list)->fd != fd)
		*list = create_chained_list(*list, fd);
	if (ft_strchr((*list)->save, '\n') && !(*list)->end)
	{
			*list = copy(*list, line);
			return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	static t_gnl	*list = NULL;
	
	if (fd < 0)
		return (-1);
	if (fd_in_list(fd, line, &list) || read_fd(line, &list, fd))
		return (1);
	if (list->close == 1 && list->close--)
		return (-1);
	if (!ft_strchr(list->save, '\n') && !list->end)
	{
		if (!list->save[0])
			return (0);
		list = copy(list, line);
		list->save = ft_strnew(0);
		return (1);
	}
	list->end = 0;
	return (0);
}
