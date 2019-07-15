/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 14:59:54 by msorin            #+#    #+#             */
/*   Updated: 2016/08/10 14:59:56 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fdf.h>
#include <unistd.h>
#include <stdlib.h>

static int		get_key(int keycode, t_elem *elm)
{
	if (keycode == 53 || keycode == 12)
	{
		clean_elem(*elm);
		exit(0);
	}
	return (1);
}

static t_int	set_rev(t_int dim, t_int fond, int cnt, char c)
{
	t_int	dir;
	t_int	rev;
	int		arv;

	dir.x = fond.x ? -1 : 1;
	dir.y = fond.y ? -1 : 1;
	if (c == 'x')
	{
		arv = cnt >= dim.y ? cnt - dim.y + (dir.y == -1) : 0;
		rev.x = fond.x + (arv * dir.x);
		rev.y = arv ? (dim.y) * (dir.y == 1) : fond.y + (cnt * dir.y);
		rev.y -= rev.y == dim.y ? 1 : 0;
	}
	else
	{
		arv = cnt >= dim.x ? cnt - dim.x + (dir.x == -1) : 0;
		rev.x = arv ? (dim.x) * (dir.x == 1) : fond.x + (cnt * dir.x);
		rev.y = fond.y + (arv * dir.y);
		rev.x -= rev.x == dim.x ? 1 : 0;
	}
	return (rev);
}

static t_int	set_it(t_int dim, t_int fond, int cnt, char c)
{
	t_int	dir;
	t_int	it;
	int		dep;

	dir.x = fond.x ? -1 : 1;
	dir.y = fond.y ? -1 : 1;
	if (c == 'x')
	{
		dep = cnt >= dim.x ? 1 + (cnt - dim.x) : 0;
		it.x = dep ? (dim.x - 1) * (dir.x == 1) : fond.x + (cnt * dir.x);
		it.y = fond.y + (dep * dir.y);
	}
	else
	{
		dep = cnt >= dim.y ? 1 + (cnt - dim.y) : 0;
		it.x = fond.x + (dep * dir.x);
		it.y = dep ? (dim.y - 1) * (dir.y == 1) : fond.y + (cnt * dir.y);
	}
	return (it);
}

static void		in_loop(t_elem elm, t_int fond, t_int dir, t_int min)
{
	t_int	it;
	t_int	dep;
	t_int	rev;
	int		cnt;
	char	c;

	c = get_fond_2(elm.calc->o_z, fond);
	cnt = 0;
	while (cnt < (elm.map->c_map.x + elm.map->c_map.y) - 1)
	{
		dep = set_it(elm.map->c_map, fond, cnt, c);
		rev = set_rev(elm.map->c_map, fond, cnt, c);
		it = dep;
		while (get_while_bool_norme(it, rev, dir, c))
		{
			printf_mlx(it, elm, min, dir);
			it.x = c == 'x' ? it.x - dir.x : it.x + dir.x;
			it.y = c == 'y' ? it.y - dir.y : it.y + dir.y;
		}
		cnt++;
	}
}

double			fdf(t_elem elm)
{
	t_int	min;
	t_int	fond;
	t_int	dir;

	fond = get_fond(elm.calc->o_z, elm.map->c_map);
	dir = get_dir(fond);
	min = get_min(elm.calc->pos_col, elm.map->c_map);
	in_loop(elm, fond, dir, min);
	mlx_key_hook(EMLX.win, get_key, &elm);
	mlx_loop(EMLX.mlx);
	return (0);
}
