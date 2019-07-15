/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:42:23 by msorin            #+#    #+#             */
/*   Updated: 2016/11/15 16:44:05 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

t_aff		**copy_calc(t_aff **calc, t_int d)
{
	t_aff	**ret;
	t_int	it;

	ret = (t_aff **)ft_memalloc(sizeof(t_aff *) * d.y);
	it.y = 0;
	while (it.y < d.y)
	{
		ret[it.y] = (t_aff *)ft_memalloc(sizeof(t_aff) * d.x);
		it.x = 0;
		while (it.x < d.x)
		{
			ret[it.y][it.x].x = calc[it.y][it.x].x;
			ret[it.y][it.x].y = calc[it.y][it.x].y;
			ret[it.y][it.x].z = calc[it.y][it.x].z;
			it.x++;
		}
		it.y++;
	}
	return (ret);
}

double		*init_double(double *db, size_t sz)
{
	db = (double *)ft_memalloc(sizeof(double) * sz);
	return (db);
}

t_aff		*init_t_aff(t_aff *ta, size_t sz)
{
	ta = (t_aff *)ft_memalloc(sizeof(t_aff) * sz);
	return (ta);
}

void		init_map(t_map *map)
{
	map->c_map.x = 0;
	map->c_map.y = 0;
	map->mm = 0;
	map->map = (int**)ft_memalloc(0);
}

void		init_calc(t_calc *calc, t_map map)
{
	calc->o_z = (double **)ft_memalloc(sizeof(double *) * map.c_map.y);
	calc->o_z = ft_tdoublemap(calc->o_z, init_double, map.c_map.y, map.c_map.x);
	PCPC = (t_aff **)ft_memalloc(sizeof(t_aff *) * map.c_map.y);
	PCPC = ft_tt_affmap(PCPC, init_t_aff, map.c_map.y, map.c_map.x);
	PCCP = (t_aff **)ft_memalloc(sizeof(t_aff *) * map.c_map.y);
	PCCP = ft_tt_affmap(PCCP, init_t_aff, map.c_map.y, map.c_map.x);
}
