/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 14:27:40 by msorin            #+#    #+#             */
/*   Updated: 2015/02/08 16:14:16 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static void		ft_memtab(char **tab, char const *s, char c, int i)
{
	int			start;
	int			y;

	start = -1;
	y = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (start >= 0)
		{
			tab[y] = ft_strsub(s, start, i - start);
			start = -1;
			y++;
		}
		if (s[i] != '\0')
			i++;
	}
	tab[y] = NULL;
}

static char		**ft_tab_one(char **tab, char const *s)
{
	size_t		size;

	size = ft_strlen(s);
	tab = (char **)ft_memalloc(sizeof(char *) * 2);
	if (size == 0)
	{
		tab[0] = (char *)ft_memalloc(sizeof(char) * 1);
		tab[0][0] = '\0';
	}
	else
		tab[0] = ft_strdup(s);
	tab[1] = NULL;
	return (tab);
}

char			**ft_strsplit(char const *s, char c, size_t *ts)
{
	int			i;
	char		**tab;

	tab = NULL;
	if (!s)
		return (ft_tab_one(tab, NULL));
	*ts = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			(*ts)++;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[i] != '\0')
			i++;
	}
	if (*ts == 0)
		return (ft_tab_one(tab, s));
	tab = (char **)ft_memalloc(sizeof(char *) * (*ts + 1));
	ft_memtab(tab, s, c, 0);
	return (tab);
}
