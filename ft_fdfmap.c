/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdfmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 11:22:52 by msorin            #+#    #+#             */
/*   Updated: 2016/11/14 11:43:16 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fdf.h>

static t_aff	*ft_affaffmap(t_aff *aff, t_aff rot, t_aff (*f)(t_aff, t_aff),
			size_t d)
{
	size_t	i;

	if (!aff || !f)
		return (aff);
	i = 0;
	while (i < d)
	{
		aff[i] = f(aff[i], rot);
		i++;
	}
	return (aff);
}

t_aff			**ft_tt_affmap(t_aff **aff, t_aff *(*f)(t_aff*, size_t),
			size_t d1, size_t d2)
{
	size_t	i;

	if (!aff || !f)
		return (aff);
	i = 0;
	while (i < d1)
	{
		aff[i] = f(aff[i], d2);
		i++;
	}
	return (aff);
}

t_aff			**ft_taffmapmap(t_aff **aff, t_map map,
			t_aff *(*f)(t_aff*, t_map, size_t, size_t), t_int it)
{
	int	i;

	if (!aff || !f)
		return (aff);
	i = 0;
	while (i < it.y)
	{
		aff[i] = f(aff[i], map, it.x, i);
		i++;
	}
	return (aff);
}

t_aff			**ft_taffaffmap(t_aff **aff, t_aff rot,
			t_aff (*f)(t_aff, t_aff), t_int it)
{
	int	i;

	if (!aff || !f)
		return (aff);
	i = 0;
	while (i < it.y)
	{
		aff[i] = ft_affaffmap(aff[i], rot, f, it.x);
		i++;
	}
	return (aff);
}
