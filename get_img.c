/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 15:51:56 by msorin            #+#    #+#             */
/*   Updated: 2016/11/25 15:51:59 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <mlx.h>

static t_int	get_dif_x(t_int it, t_aff **pos_col, t_int dim, t_int dir)
{
	t_int	ret;

	if ((it.x == 0 && dir.x > 0) || (it.x == dim.x - 1 && dir.x < 0))
	{
		ret.x = 0;
		ret.y = 0;
		return (ret);
	}
	ret.x = ft_round(pos_col[it.y][it.x].x - pos_col[it.y][it.x - dir.x].x);
	ret.y = ft_round(pos_col[it.y][it.x].y - pos_col[it.y][it.x - dir.x].y);
	return (ret);
}

static t_int	get_dif_y(t_int it, t_aff **pos_col, t_int dim, t_int dir)
{
	t_int	ret;

	if ((it.y == 0 && dir.y > 0) || (it.y == dim.y - 1 && dir.y < 0))
	{
		ret.x = 0;
		ret.y = 0;
		return (ret);
	}
	ret.x = ft_round(pos_col[it.y][it.x].x - pos_col[it.y - dir.y][it.x].x);
	ret.y = ft_round(pos_col[it.y][it.x].y - pos_col[it.y - dir.y][it.x].y);
	return (ret);
}

static void		print_line_x(t_int it, t_elem elm, t_int min, t_int dir)
{
	t_int	cnt;
	t_int	d1;
	t_aff	col;
	t_aff	div;

	d1 = get_dif_x(it, EPC, elm.map->c_map, dir);
	cnt.x = 0;
	cnt.y = 0;
	col.y = EPC[it.y][it.x].z;
	col.x = d1.x || d1.y ? EPC[it.y][it.x - dir.x].z : 0;
	div.x = d1.y ? (double)d1.x / (double)d1.y : 1;
	div.y = d1.x ? (double)d1.y / (double)d1.x : 1;
	while (ft_abs(cnt.y) <= ft_abs(d1.y) && ft_abs(cnt.x) <= ft_abs(d1.x)
		&& !(ft_abs(cnt.y) == ft_abs(d1.y) && ft_abs(cnt.x) == ft_abs(d1.x)))
	{
		col.z = get_color(F_MA(cnt.x, cnt.y), F_MA(d1.x, d1.y), col,
			elm.map->map[it.y][it.x] - elm.map->map[it.y][it.x - dir.x]);
		mlx_pixel_put(EMLX.mlx, EMLX.win,
			cnt.x + EPC[it.y][it.x - dir.x].x + min.x,
			cnt.y + EPC[it.y][it.x - dir.x].y + min.y, col.z);
		cnt.x = ft_abs((int)div.x) >= 1 ? cnt.x + ft_signe(d1.x)
			: (int)(div.x * (double)(cnt.y + 1));
		cnt.y = ft_abs((int)div.y) >= 1 ? cnt.y + ft_signe(d1.y)
			: (int)(div.y * (double)cnt.x);
	}
}

static void		print_line_y(t_int it, t_elem elm, t_int min, t_int dir)
{
	t_int	cnt;
	t_int	d2;
	t_aff	col;
	t_aff	div;

	d2 = get_dif_y(it, EPC, elm.map->c_map, dir);
	cnt.x = 0;
	cnt.y = 0;
	col.y = EPC[it.y][it.x].z;
	col.x = d2.x || d2.y ? EPC[it.y - dir.y][it.x].z : 0;
	div.x = d2.y ? (double)d2.x / (double)d2.y : 1;
	div.y = d2.x ? (double)d2.y / (double)d2.x : 1;
	while (ft_abs(cnt.y) <= ft_abs(d2.y) && ft_abs(cnt.x) <= ft_abs(d2.x)
		&& !(ft_abs(cnt.y) == ft_abs(d2.y) && ft_abs(cnt.x) == ft_abs(d2.x)))
	{
		col.z = get_color(F_MA(cnt.x, cnt.y), F_MA(d2.x, d2.y), col,
			elm.map->map[it.y][it.x] - elm.map->map[it.y - dir.y][it.x]);
		mlx_pixel_put(EMLX.mlx, EMLX.win,
			cnt.x + EPC[it.y - dir.y][it.x].x + min.x,
			cnt.y + EPC[it.y - dir.y][it.x].y + min.y, col.z);
		cnt.x = ft_abs((int)div.x) >= 1 ? cnt.x + ft_signe(d2.x)
			: (int)(div.x * (double)(cnt.y + 1));
		cnt.y = ft_abs((int)div.y) >= 1 ? cnt.y + ft_signe(d2.y)
			: (int)(div.y * (double)cnt.x);
	}
}

void			printf_mlx(t_int it, t_elem elm, t_int min, t_int dir)
{
	print_line_x(it, elm, min, dir);
	print_line_y(it, elm, min, dir);
}
