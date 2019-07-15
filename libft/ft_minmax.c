/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 11:55:34 by msorin            #+#    #+#             */
/*   Updated: 2016/08/10 11:55:35 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int		ft_max(int a, int b)
{
	int	ret;

	return ((ret = a < b ? b : a));
}

int		ft_min(int a, int b)
{
	int	ret;

	return ((ret = a > b ? b : a));
}

double	ft_fmax(double a, double b)
{
	double	ret;

	return ((ret = a < b ? b : a));
}

double	ft_fmin(double a, double b)
{
	double	ret;

	return ((ret = a > b ? b : a));
}
