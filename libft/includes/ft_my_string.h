/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_my_string.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 04:57:33 by memelia           #+#    #+#             */
/*   Updated: 2019/11/12 13:28:04 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MY_STRING_H
# define FT_MY_STRING_H
# define BUFF_SIZE 17
# define ABS(nbr) (nbr <= 0.0) ? -nbr : nbr

# include "libft.h"

/*
**	Function`s for some work with string
*/

int					ft_atoi(const char *str);
int					ft_getnbr(char *str);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
int					ft_len_arr(char **arr);
char				*ft_strcat(char *dst, const char *src);
char				*ft_strchr(const char *s, int c);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
int					ft_strequ(char const *s1, char const *s2);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strjoin_free(char *s1, char *s2, int flag1, int flag2);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
size_t				ft_strlen(const char *s);
char				*ft_strlow(char *s);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strncat(char *dst, const char *src, size_t len);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strnew(size_t size);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strrev(char *s);
char				**ft_strsplit(char const *str, char symb);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strtrim(char const *s);
char				*ft_strup(char *s);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					get_next_line(const int fd, char **line);
char				*read_file(int size, char *name);
char				*read_big_file(char *file_str, char *filename);
double				ft_atof(const char *str);
int					ft_isnumber(int c);

#endif
