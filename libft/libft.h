/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msorin <msorin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 11:49:07 by msorin            #+#    #+#             */
/*   Updated: 2016/11/29 17:54:44 by msorin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>

# define BUFF_SIZE 2048

typedef unsigned int	t_flags;
typedef struct s_entry	t_entry;

struct		s_entry
{
	t_entry	*next;
	int		fd;
	char	*buf;
};

int			ft_abs(int x);
int			ft_atoi(const char *str);
int			ft_max(int a, int b);
int			ft_min(int a, int b);
int			ft_round(double d);
int			ft_signe(int nb);
int			get_next_line(const int fd, char **line);

void		ft_bzero(void *s, size_t n);
void		ft_error(const char *str);

double		ft_atof(const char *str);
double		ft_fmax(double a, double b);
double		ft_fmin(double a, double b);

size_t		ft_strclen(const char *s, char c);
size_t		ft_strlen(const char *s);

char		*ft_strchr(const char *s, int c);
char		*ft_strcpy(char *s1, const char *s2);
char		*ft_strdup(const char *s1);
char		*ft_strncat(char *s1, const char *s2, size_t n);
char		*ft_strnew(size_t size);
char		*ft_strnjoinf(char *s1, char *s2, size_t n, t_flags flag);
char		*ft_strsub(char const *s, unsigned int start, size_t len);

void		*ft_memalloc(size_t size);
void		*ft_memcpy(void *s1, const void *s2, size_t n);
void		*ft_memmove(void *s1, const void *s2, size_t n);
void		*ft_memset(void *b, int c, size_t len);

int			**ft_reallinttab(int **src, size_t size, size_t ln);

char		**ft_strsplit(char const *s, char c, size_t *ts);

double		**ft_tdoublemap(double **t, double *(*f)(double*, size_t),
				size_t d1, size_t d2);

#endif
