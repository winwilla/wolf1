/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 00:04:49 by memelia           #+#    #+#             */
/*   Updated: 2020/05/18 00:05:22 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static bool			check_borders(t_map *map)
{
	int				i;

	if (!ft_find_symb_in_str_arr(map->level, '0'))
		return (false);
	if (ft_strchr(map->level[0], '0')
		|| ft_strchr(map->level[map->height - 1], '0'))
		return (false);
	i = 0;
	while (++i < map->height - 1)
	{
		if (map->level[i][0] == '0' || map->level[i][map->width - 1] == '0')
			return (false);
	}
	return (true);
}

static bool			check_symbols_in_map(t_map *map)
{
	int				i;
	int				k;

	i = -1;
	while (map->level[++i])
	{
		k = -1;
		while (map->level[i][++k])
		{
			if ((((int)map->level[i][k] >= T_11 &&
				(int)map->level[i][k] <= T_38)) || (int)map->level[i][k] == 48)
				continue ;
			else
				return (false);
		}
	}
	if (map->level[1][1] != 48)
		return (false);
	return (true);
}

static bool			count_height(char *file, t_map *map)
{
	int				i;
	int				file_len;

	i = map->width;
	if ((file_len = ft_strlen_without_symb(' ', file)) == 0)
		return (false);
	while (i <= file_len)
	{
		i += map->width;
		map->height++;
	}
	return (true);
}

static void			fill_map(char *file, t_map **map)
{
	int				i;
	int				k;
	char			*file_without_whitespace;

	i = -1;
	k = 0;
	file_without_whitespace = ft_strnew_without_symb(' ', file);
	(*map)->level =
		(char **)ft_memalloc(sizeof(char *) * ((*map)->height + 1));
	while (++i < (*map)->height)
	{
		(*map)->level[i] =
			ft_strsub(file_without_whitespace, k, (*map)->width);
		k += (*map)->width;
	}
	ft_strdel(&file_without_whitespace);
}

bool				read_map(const char *level_name, t_map *map)
{
	char			*file;

	if (!(file = read_file(map)))
		return (false);
	if (!count_height(file, map))
	{
		ft_strdel(&file);
		return (false);
	}
	if (map->height < 3 || map->width < 3)
	{
		ft_strdel(&file);
		return (false);
	}
	fill_map(file, &map);
	ft_strdel(&file);
	if (!check_symbols_in_map(map))
		return (reader_error(&map));
	if (!check_borders(map))
		return (reader_error(&map));
	return (true);
}
