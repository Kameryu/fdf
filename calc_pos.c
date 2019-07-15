/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:38:35 by msorin            #+#    #+#             */
/*   Updated: 2016/11/18 11:38:39 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <stdlib.h>

static t_aff	**ft_setpos(t_aff **pos, t_aff **calc, t_int it)
{
	int		i;
	int		j;

	j = 0;
	while (j < it.y)
	{
		i = 0;
		while (i < it.x)
		{
			pos[j][i].x = calc[j][i].x * (it.x > 64 ? 2048 / it.x : 32);
			pos[j][i].y = calc[j][i].y * (it.y > 32 ? 1024 / it.y : 32);
			i++;
		}
		j++;
	}
	return (pos);
}

static t_aff	**set_z0(t_aff **aff, t_int it)
{
	int			i;
	int			j;

	j = -1;
	while (++j < it.y)
	{
		i = -1;
		while (++i < it.x)
			aff[j][i].z = 0;
	}
	return (aff);
}

static void		calc_oz(t_calc *calc, t_aff rot,
	t_aff (*f)(t_aff, t_aff), t_int it)
{
	t_aff		**tmp;
	int			i;
	int			j;

	tmp = copy_calc(PCCP, it);
	tmp = set_z0(tmp, it);
	tmp = ft_taffaffmap(tmp, rot, f, it);
	PCCP = ft_taffaffmap(PCCP, rot, f, it);
	j = -1;
	while (++j < it.y)
	{
		i = -1;
		while (++i < it.x)
			calc->o_z[j][i] = tmp[j][i].z;
		free(tmp[j]);
	}
	free(tmp);
}

static t_aff	*set_calc_base(t_aff *aff, t_map map, size_t d, size_t it)
{
	size_t	i;

	i = 0;
	while (i < d)
	{
		aff[i].x = (double)i;
		aff[i].y = (double)it;
		aff[i].z = (double)map.map[it][i];
		i++;
	}
	return (aff);
}

void			calc_pos(t_calc *calc, t_map map, t_aff rotate)
{
	PCCP = ft_taffmapmap(PCCP, map, set_calc_base,
		map.c_map);
	calc_oz(calc, rotate, set_rotate, map.c_map);
	PCPC = ft_setpos(PCPC, PCCP, map.c_map);
}
