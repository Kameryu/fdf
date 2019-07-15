/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reallinttab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/29 10:02:27 by msorin            #+#    #+#             */
/*   Updated: 2016/08/10 12:28:56 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

int			**ft_reallinttab(int **src, size_t size, size_t ln)
{
	int		**dest;
	size_t	i;
	size_t	j;

	dest = ft_memalloc((size + 1) * sizeof(int*));
	i = 0;
	while (i < size)
	{
		dest[i] = (int *)ft_memalloc(sizeof(int) * ln);
		j = 0;
		while (j < ln)
		{
			dest[i][j] = src[i][j];
			j++;
		}
		free(src[i]);
		i++;
	}
	free(src);
	dest[size] = NULL;
	return (dest);
}
