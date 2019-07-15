/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 10:52:36 by msorin            #+#    #+#             */
/*   Updated: 2016/06/28 11:25:41 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>
#include <stdlib.h>

static int		ft_read(char **line, char **buf, char c, unsigned int max_s)
{
	unsigned int	size;

	if (!*buf || !**buf)
		return (-1);
	size = ft_min(ft_strclen(*buf, c), max_s);
	if (!ft_strchr(*buf, c))
	{
		if (!(*line = ft_strnjoinf(*line, *buf, size, 1)))
			return (-42);
		ft_memset(*buf, '\0', BUFF_SIZE);
		return (-1);
	}
	if (size == ft_strlen(*buf))
	{
		if (!(*line = ft_strnjoinf(*line, *buf, size, 1)))
			return (-42);
		ft_memset(*buf, '\0', BUFF_SIZE);
		return (0);
	}
	if (!(*line = ft_strnjoinf(*line, *buf, size, 1)))
		return (-42);
	ft_memmove(*buf, (*buf) + size + 1, max_s);
	ft_memset((*buf) + max_s - size, '\0', BUFF_SIZE - max_s);
	return (1);
}

static t_entry	*ft_new(const int fd)
{
	t_entry	*res;

	res = (t_entry*)malloc(sizeof(t_entry));
	if (!res)
		return (NULL);
	res->next = NULL;
	res->fd = fd;
	res->buf = (char*)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1));
	ft_bzero(res->buf, sizeof(char) * (BUFF_SIZE + 1));
	if (!res->buf)
		return (NULL);
	return (res);
}

static t_entry	*ft_search(t_entry **list, const int fd)
{
	t_entry	*it;

	it = *list;
	if (*list)
	{
		while (it->next)
		{
			if (it->fd == fd)
				return (it);
			it = it->next;
		}
		if (it->fd == fd)
			return (it);
		it->next = ft_new(fd);
		return (it->next);
	}
	*list = ft_new(fd);
	return (*list);
}

static int		ft_free(t_entry *list, const int fd)
{
	t_entry		*temp;

	if (!list->next)
	{
		free(list->buf);
		free(list);
		return (1);
	}
	while (list->next)
	{
		if (list->next->fd == fd)
		{
			temp = list->next;
			list->next = list->next->next;
			free(temp->buf);
			free(temp);
		}
		list = list->next;
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_entry	*list = NULL;
	t_entry			*entry;
	int				res;

	if (!line || fd < 0 || fd == 1 || fd == 2)
		return (-1);
	if (!(entry = ft_search(&list, fd)))
		return (-1);
	if (!(*line = ft_strdup("")))
		return (-1);
	if ((res = ft_read(line, &(entry->buf), '\n', BUFF_SIZE)) > 0)
		return (1);
	while ((res = read(fd, entry->buf, BUFF_SIZE)) > 0)
	{
		entry->buf[BUFF_SIZE] = '\0';
		if (res < 0)
			return (-1);
		if ((res = ft_read(line, &(entry->buf), '\n', res) > 0))
			return (1);
		if (!res && !entry->buf)
			return (ft_free(list, fd));
		if (res < 0)
			return (-1);
	}
	return (res = (res > 0) ? 1 : res);
}
