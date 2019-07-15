/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoinf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 14:51:35 by msorin            #+#    #+#             */
/*   Updated: 2015/10/22 14:54:58 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strnjoinf(char *s1, char *s2, size_t n, t_flags flag)
{
	char	*res;

	res = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strcpy(res, s1);
	ft_strncat(res, s2, n);
	if (flag & 1)
		free(s1);
	if (flag & 2)
		free(s2);
	return (res);
}
