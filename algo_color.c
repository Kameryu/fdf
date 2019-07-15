/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 15:23:02 by msorin            #+#    #+#             */
/*   Updated: 2016/09/30 11:06:55 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static double	ft_sign(double x, double y)
{
	if ((x > 0 && y < 0) || (x < 0 && y > 0))
		return (0);
	return (1);
}

static t_aff	def_col(void)
{
	t_aff		def;

	def.x = OOF;
	def.y = FOO;
	def.z = FFF;
	return (def);
}

static t_aff	set_color(double it, double col_it, t_aff set, t_aff ret)
{
	double		i;

	if (!(i = 0) && set.x)
	{
		while (i < it && !ret.x && ret.y < OOF)
			ret.y += ++i && col_it ? col_it : (double)(i - 1 > it / 2);
		if (ret.y > OOF)
			ret.y = OOF;
		while (i < it && ret.x < set.x)
			ret.x += ++i && col_it ? col_it : (double)(i - 1 > it / 2);
		if (ret.x > set.x)
			ret.x = set.x;
	}
	if ((!set.z || set.z < ret.z) && i < it)
	{
		while (i < it && ret.z > set.z)
			ret.z -= ++i && col_it ? col_it : (double)(i - 1 > it / 2);
		if (ret.z < set.z)
			ret.z = set.z;
		while (i < it && ret.y > set.y)
			ret.y -= ++i && col_it ? col_it : (double)(i - 1 > it / 2);
		if (ret.y < set.y)
			ret.y = set.y;
	}
	return (ret);
}

int				get_color(double it, double max, t_aff col, double dir)
{
	int			rgb[3];
	t_int		cc;
	t_aff		t1;
	t_aff		t2;

	if (max == 0)
		return ((cc.x = col.x == col.y ? col.x : FFF));
	rgb[0] = (((int)col.y & FOO) >> 16) - (((int)col.x & FOO) >> 16);
	rgb[1] = (((int)col.y & OFO) >> 8) - (((int)col.x & OFO) >> 8);
	rgb[2] = ((int)col.y & OOF) - ((int)col.x & OOF);
	cc.x = ft_sign(rgb[0], rgb[2]) ? (ft_abs(rgb[0])
		+ ft_abs(rgb[1]) + ft_abs(rgb[2])) : ((OOF - (((int)col.y & OFO) >> 8))
		+ (OOF - (((int)col.x & OFO) >> 8)) + ft_abs(rgb[0]) + ft_abs(rgb[2]));
	cc.y = cc.x / max + ((cc.x % (int)max) ? 1 : 0);
	t1.x = dir < 0 ? (int)col.y & OOF : ((int)col.y & FOO) >> 16;
	t1.y = ((int)col.y & OFO) >> 8;
	t1.z = dir > 0 ? (int)col.y & OOF : ((int)col.y & FOO) >> 16;
	t2.x = dir < 0 ? (int)col.x & OOF : ((int)col.x & FOO) >> 16;
	t2.y = ((int)col.x & OFO) >> 8;
	t2.z = dir > 0 ? (int)col.x & OOF : ((int)col.x & FOO) >> 16;
	t2 = set_color(it, cc.y, t1, t2);
	rgb[0] = dir < 0 ? t2.z : t2.x;
	rgb[1] = t2.y;
	rgb[2] = dir > 0 ? t2.z : t2.x;
	return ((rgb[0] << 16) + (rgb[1] << 8) + rgb[2]);
}

void			ft_set_color(t_calc *calc, t_map map)
{
	t_aff		col;
	int			i;
	int			j;

	col = def_col();
	j = 0;
	while (j < map.c_map.y)
	{
		i = -1;
		while (++i < map.c_map.x)
			PCPC[j][i].z = get_color(map.map[j][i] + map.mm, map.ecart, col, 1);
		j++;
	}
}
