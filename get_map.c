/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:17:51 by msorin            #+#    #+#             */
/*   Updated: 2016/11/29 18:01:56 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static void	this_error(char *msg, t_map *map)
{
	int		i;

	i = -1;
	while (++i < map->c_map.y)
		free(map->map[i]);
	free(map->map);
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

static int	set_map(t_map *map, char *line)
{
	char	**cut;
	int		i;
	int		t;
	size_t	ts;

	ts = 0;
	cut = ft_strsplit(line, ' ', &ts);
	if (map->c_map.x && ts != (size_t)(map->c_map.x))
		return (0);
	else if (!map->c_map.x)
		map->c_map.x = ts;
	i = 0;
	map->map[map->c_map.y] = (int*)ft_memalloc(sizeof(int) * ts);
	while (i < map->c_map.x)
	{
		t = ft_atoi(cut[i]);
		free(cut[i]);
		map->mm = ft_max(ft_abs(t), map->mm);
		map->map[map->c_map.y][i] = t;
		i++;
	}
	free(cut);
	map->c_map.y += 1;
	return (1);
}

void		get_map(char *file, t_map *map)
{
	int		fd;
	int		res;
	char	*line;

	if ((fd = open(file, O_RDONLY)) == -1)
		this_error("File failed to open.", map);
	line = NULL;
	while ((res = get_next_line(fd, &line)) == 1)
	{
		map->map = ft_reallinttab(map->map, map->c_map.y, map->c_map.x);
		if (!(set_map(map, line)))
			this_error("Map bad format.", map);
		free(line);
		line = NULL;
	}
	if (res == -1)
		this_error("get_next_line", map);
	if (line)
		free(line);
	close(fd);
	if (map->c_map.x <= 1 || map->c_map.y <= 1)
		this_error("need at least 2 'x' and 2 'y'", map);
	map->ecart = 2 * map->mm;
}
