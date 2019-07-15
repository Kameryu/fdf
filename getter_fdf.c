/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getter_fdf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:07:50 by msorin            #+#    #+#             */
/*   Updated: 2016/11/24 16:08:39 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_int		get_dir(t_int fond)
{
	t_int	ret;

	ret.x = fond.x ? -1 : 1;
	ret.y = fond.y ? -1 : 1;
	return (ret);
}

t_int		get_fond(double **o_z, t_int dim)
{
	t_int	ret;

	if (o_z[0][0] < o_z[0][dim.x - 1])
	{
		ret.x = 0;
		if (o_z[0][0] < o_z[dim.y - 1][0])
			ret.y = 0;
		else
			ret.y = dim.y - 1;
	}
	else
	{
		ret.x = dim.x - 1;
		if (o_z[0][dim.x - 1] < o_z[dim.y - 1][dim.x - 1])
			ret.y = 0;
		else
			ret.y = dim.y - 1;
	}
	return (ret);
}

char		get_fond_2(double **o_z, t_int fond)
{
	t_int	t1;
	t_int	t2;

	t1.x = fond.x ? fond.x - 1 : 1;
	t1.y = fond.y;
	t2.x = fond.x;
	t2.y = fond.y ? fond.y - 1 : 1;
	if (o_z[t1.y][t1.x] < o_z[t2.y][t2.x])
		return ('x');
	return ('y');
}

t_int		get_min(t_aff **calc, t_int it)
{
	t_int	ret;
	int		i;
	int		j;

	ret.x = calc[0][0].x < 0 ? (int)calc[0][0].x - 1 : (int)calc[0][0].x + 1;
	ret.y = calc[0][0].y < 0 ? (int)calc[0][0].y - 1 : (int)calc[0][0].y + 1;
	j = 0;
	while (j < it.y)
	{
		i = 0;
		while (i < it.x)
		{
			ret.x = (int)calc[j][i].x < ret.x ? (int)calc[j][i].x - 1 : ret.x;
			ret.y = (int)calc[j][i].y < ret.y ? (int)calc[j][i].y - 1 : ret.y;
			i++;
		}
		j++;
	}
	ret.x = 32 - ret.x;
	ret.y = 32 - ret.y;
	return (ret);
}
