/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_big_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:20:45 by memelia           #+#    #+#             */
/*   Updated: 2020/01/11 19:43:01 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char					*read_big_file(char *file_str, char *filename)
{
	int					i;
	int					fd;
	int					size;
	char				buf[500];

	i = -1;
	if (!filename)
		return (NULL);
	if ((fd = open(filename, O_RDONLY)) < 0)
		return (NULL);
	if ((read(fd, buf, 0)) < 0)
		return (NULL);
	if ((size = (read(fd, buf, 500))) <= 0)
		return (NULL);
	file_str = (char *)ft_safe_malloc(sizeof(char) * size);
	while (++i < size)
		file_str[i] = buf[i];
	file_str[i] = '\0';
	close(fd);
	return (file_str);
}
