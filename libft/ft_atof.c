/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 14:51:19 by msorin            #+#    #+#             */
/*   Updated: 2016/11/18 14:51:22 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static double	get_decim(char *t)
{
	double	ret;
	double	div;

	ret = 0;
	div = 1;
	while (*t != '\0' && *t >= '0' && *t <= '9')
	{
		ret = ret * 10 - '0' + *t;
		div *= 10;
		t++;
	}
	ret /= div;
	return (ret);
}

static int		ft_test_sign(char c)
{
	if (c == '-')
		return (-1);
	else if (c == '+' || c == '.' || (c >= '0' && c <= '9'))
		return (1);
	else
		return (0);
}

double			ft_atof(const char *str)
{
	char	*t;
	int		sign;
	double	number;

	if (!str)
		return (0);
	t = (char*)str;
	while (*t == ' ' || *t == '\t' || *t == '\n'
			|| *t == '\r' || *t == '\v' || *t == '\f')
		t++;
	sign = ft_test_sign(*t);
	if (sign == 0)
		return (0);
	if (sign == -1 || *t == '+')
		t++;
	number = 0;
	while (*t >= '0' && *t <= '9')
	{
		number = number * 10 - '0' + *t;
		t++;
	}
	if (*t == '.')
		number += get_decim(t + 1);
	number *= (double)sign;
	return (number);
}
