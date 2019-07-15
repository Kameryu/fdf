/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_fdf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:32:56 by msorin            #+#    #+#             */
/*   Updated: 2016/11/19 11:31:43 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_FDF_H
# define STRUCT_FDF_H

typedef struct s_int	t_int;
typedef struct s_aff	t_aff;
typedef struct s_mlx	t_mlx;
typedef struct s_map	t_map;
typedef struct s_calc	t_calc;
typedef struct s_elem	t_elem;

struct		s_int
{
	int		x;
	int		y;
};

struct		s_aff
{
	double	x;
	double	y;
	double	z;
};

struct		s_mlx
{
	void	*mlx;
	void	*win;
	t_int	wsz;
};

struct		s_map
{
	int		**map;
	t_int	c_map;
	size_t	mm;
	size_t	ecart;
};

struct		s_calc
{
	double	**o_z;
	t_aff	**pos_col;
	t_aff	**calc_pos;
};

struct		s_elem
{
	t_mlx	mlx;
	t_map	*map;
	t_calc	*calc;
};

#endif
