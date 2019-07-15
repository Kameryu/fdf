/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 14:20:55 by msorin            #+#    #+#             */
/*   Updated: 2015/01/26 14:20:58 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void			*zone;

	if (!(zone = malloc(size)))
		ft_error("Memory allocation failed.");
	ft_bzero(zone, size);
	return (zone);
}
