/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_win_and_norme.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 11:42:43 by msorin            #+#    #+#             */
/*   Updated: 2016/11/29 11:42:47 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

int			get_while_bool_norme(t_int it, t_int rev, t_int dir, char c)
{
	return (!(((it.x > rev.x && dir.x > 0 && c == 'y')
				|| (it.x < rev.x && dir.x < 0 && c == 'y')
				|| (it.x > rev.x && dir.x < 0 && c == 'x')
				|| (it.x < rev.x && dir.x > 0 && c == 'x'))
			|| ((it.y > rev.y && dir.y > 0 && c == 'x')
				|| (it.y < rev.y && dir.y < 0 && c == 'x')
				|| (it.y > rev.y && dir.y < 0 && c == 'y')
				|| (it.y < rev.y && dir.y > 0 && c == 'y'))));
}

t_int		get_win_size(t_calc calc, t_map map)
{
	t_int	w_size;
	t_aff	min;
	t_aff	max;
	int		i;
	int		j;

	min.x = 0;
	min.y = 0;
	max.x = 0;
	max.y = 0;
	j = -1;
	while (++j < map.c_map.y)
	{
		i = -1;
		while (++i < map.c_map.x)
		{
			min.x = TERN ? CPC[j][i].x : ft_fmin(CPC[j][i].x, min.x);
			min.y = TERN ? CPC[j][i].y : ft_fmin(CPC[j][i].y, min.y);
			max.x = TERN ? CPC[j][i].x : ft_fmax(CPC[j][i].x, max.x);
			max.y = TERN ? CPC[j][i].y : ft_fmax(CPC[j][i].y, max.y);
		}
	}
	w_size.x = ft_abs(ft_round(max.x - min.x)) + 64;
	w_size.y = ft_abs(ft_round(max.y - min.y)) + 64;
	return (w_size);
}
