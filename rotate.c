/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 10:58:19 by msorin            #+#    #+#             */
/*   Updated: 2016/11/18 10:58:26 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>
#include <math.h>

static t_aff	calculate_rx(t_aff s, double ang)
{
	t_aff	ret;

	ret.x = s.x;
	ret.y = s.y * cos(ang) - s.z * sin(ang);
	ret.z = s.y * sin(ang) + s.z * cos(ang);
	return (ret);
}

static t_aff	calculate_ry(t_aff s, double ang)
{
	t_aff	ret;

	ret.x = s.z * sin(ang) + s.x * cos(ang);
	ret.y = s.y;
	ret.z = s.z * cos(ang) - s.x * sin(ang);
	return (ret);
}

static t_aff	calculate_rz(t_aff s, double ang)
{
	t_aff	ret;

	ret.x = s.x * cos(ang) - s.y * sin(ang);
	ret.y = s.x * sin(ang) + s.y * cos(ang);
	ret.z = s.z;
	return (ret);
}

t_aff			set_rotate(t_aff aff, t_aff rot)
{
	t_aff	ret;

	ret = calculate_rx(aff, rot.x);
	ret = calculate_ry(ret, rot.y);
	ret = calculate_rz(ret, rot.z);
	return (ret);
}

t_aff			get_rotate(int ac, char **av)
{
	t_aff	rot;

	rot.x = 0;
	rot.y = 0;
	rot.z = 0;
	if (3 <= ac)
		rot.x = ft_atof(av[2]);
	if (4 <= ac)
		rot.y = ft_atof(av[3]);
	if (5 == ac)
		rot.z = ft_atof(av[4]);
	return (rot);
}
