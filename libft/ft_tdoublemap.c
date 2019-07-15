/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tdoublemap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 11:06:18 by msorin            #+#    #+#             */
/*   Updated: 2016/11/10 11:15:29 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	**ft_tdoublemap(double **t, double *(*f)(double*, size_t),
			size_t d1, size_t d2)
{
	size_t	i;

	if (!t || !f)
		return (NULL);
	i = 0;
	while (i < d1)
	{
		t[i] = f(t[i], d2);
		i++;
	}
	return (t);
}
