/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 11:13:21 by msorin            #+#    #+#             */
/*   Updated: 2016/06/28 11:13:23 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <fdf.h>
#include <math.h>
#include <stdlib.h>

static void		this_error(char *str, t_elem elm)
{
	clean_elem(elm);
	ft_error(str);
}

void			clean_elem(t_elem elm)
{
	int			j;

	j = -1;
	while (++j < elm.map->c_map.y)
	{
		free(elm.map->map[j]);
		free(elm.PCCP[j]);
		free(elm.PCPC[j]);
		free(elm.calc->o_z[j]);
	}
	free(elm.map->map);
	free(elm.PCCP);
	free(elm.PCPC);
	free(elm.calc->o_z);
	if (EMLX.mlx)
		if (EMLX.win)
			mlx_destroy_window(EMLX.mlx, EMLX.win);
}

int				main(int argc, char **argv)
{
	t_elem		elm;
	t_map		map;
	t_aff		rotate;
	t_calc		calc;

	if (argc > 5)
		ft_error("To many argument.");
	if (argc == 1)
		ft_error("To few argument.");
	init_map(&map);
	get_map(argv[1], &(map));
	elm.map = &map;
	rotate = get_rotate(argc, argv);
	init_calc(&calc, map);
	calc_pos(&calc, map, rotate);
	ft_set_color(&calc, map);
	elm.calc = &calc;
	EMLX.wsz = get_win_size(calc, map);
	if (!(EMLX.mlx = mlx_init()))
		this_error("mlx_init", elm);
	if (!(EMLX.win = mlx_new_window(EMLX.mlx, EMLX.wsz.x, EMLX.wsz.y, argv[1])))
		this_error("mlx_new_window", elm);
	fdf(elm);
	clean_elem(elm);
	return (0);
}
