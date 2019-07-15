/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/28 09:37:49 by msorin            #+#    #+#             */
/*   Updated: 2016/06/28 09:39:25 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <libft.h>
# include <struct_fdf.h>

# define OOF		0x0000ff
# define OFO		0x00ff00
# define FOO		0xff0000
# define OFF		0x00ffff
# define FFO		0xffff00
# define FFF		0xffffff

# define EMLX		elm.mlx
# define CPC		calc.pos_col
# define PCCP		calc->calc_pos
# define PCPC		calc->pos_col
# define TERN		(i == 0 && j == 0)
# define F_MA(x, y)	ft_max(ft_abs(x), ft_abs(y))
# define EPC		elm.calc->pos_col

void		init_map(t_map *map);
void		get_map(char *file, t_map *map);
void		clean_elem(t_elem elm);
t_aff		get_rotate(int ac, char **av);
void		init_calc(t_calc *calc, t_map map);
double		*init_double(double *db, size_t sz);
t_aff		*init_t_aff(t_aff *ta, size_t sz);
t_aff		**ft_tt_affmap(t_aff **aff, t_aff *(*f)(t_aff*, size_t),
				size_t d1, size_t d2);
void		calc_pos(t_calc *calc, t_map map, t_aff rotate);
t_aff		**ft_taffmapmap(t_aff **aff, t_map map,
				t_aff *(*f)(t_aff*, t_map, size_t, size_t), t_int it);
t_aff		**ft_taffaffmap(t_aff **aff, t_aff rot, t_aff (*f)(t_aff, t_aff),
				t_int it);
t_aff		set_rotate(t_aff aff, t_aff rot);
void		ft_set_color(t_calc *calc, t_map map);
t_int		get_win_size(t_calc calc, t_map map);
double		fdf(t_elem elm);
int			get_color(double it, double max, t_aff col, double dir);
t_int		get_min(t_aff **calc, t_int it);
t_aff		**copy_calc(t_aff **calc, t_int d);
t_int		get_fond(double **o_z, t_int dim);
t_int		get_dir(t_int fond);
char		get_fond_2(double **o_z, t_int fond);
void		printf_mlx(t_int it, t_elem elm, t_int min, t_int dir);
int			get_while_bool_norme(t_int it, t_int rev, t_int dir, char c);

#endif
