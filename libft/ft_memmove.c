/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 11:15:49 by msorin            #+#    #+#             */
/*   Updated: 2015/01/26 11:40:11 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	*ft_memmove(void *s1, const void *s2, size_t n)
{
	char	*s3;
	size_t	i;

	i = 0;
	s3 = ft_memalloc(n);
	if (!s3)
		return (NULL);
	ft_memcpy(s3, s2, n);
	while (i < n)
	{
		((char *)s1)[i] = s3[i];
		i++;
	}
	free(s3);
	return (s1);
}
