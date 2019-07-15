/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 11:22:10 by msorin            #+#    #+#             */
/*   Updated: 2015/01/26 11:48:26 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	unsigned int	size;
	unsigned int	i;

	i = 0;
	if (s2[0] == '\0' || n == 0)
		return (s1);
	size = ft_strlen(s1);
	while ((char)s2[i] != '\0' && n > 0)
	{
		s1[size] = s2[i];
		i++;
		size++;
		n--;
	}
	s1[size] = '\0';
	return (s1);
}
