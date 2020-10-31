/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 23:53:55 by memelia           #+#    #+#             */
/*   Updated: 2020/05/17 23:54:23 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int		find_in_arr_text(int value, char *arr_id_tex)
{
	int			i;

	i = -1;
	if (!arr_id_tex[0])
		return (0);
	while (++i < NBR_TEXTURES)
	{
		if (arr_id_tex[i] == value)
			return (-1);
		if (!arr_id_tex[i])
			return (i);
	}
	return (-1);
}

static void		get_arr_text_id(char *arr_id_tex, t_env *env)
{
	int			i;
	int			id;
	int			k;

	i = -1;
	while (env->map->level[++i])
	{
		k = -1;
		while (env->map->level[i][++k])
		{
			if (env->map->level[i][k] != '0')
			{
				if ((id = find_in_arr_text((int)env->map->level[i][k],
					arr_id_tex)) != -1)
					arr_id_tex[id] = env->map->level[i][k];
			}
		}
	}
}

static void		load_special_wall(char *tex, t_tex **temp, t_env **env)
{
	int			i;

	i = -1;
	while (i++ < 4)
	{
		if (i == 0 && (tex = WALL18))
			(*temp)->id = North;
		else if (i == 1 && (tex = WALL64))
			(*temp)->id = South;
		else if (i == 2 && (tex = WALL10))
			(*temp)->id = East;
		else if (i == 3 && (tex = WALL55))
			(*temp)->id = West;
		if (!((*temp)->tex_ptr = mlx_xpm_file_to_image((*env)->mlx, tex,
				&(*temp)->width, &(*temp)->height)))
			ft_exit(LOAD_SPECIAL_WALL);
		if (!((*temp)->data = mlx_get_data_addr((*temp)->tex_ptr,
			&(*temp)->bts_pr_px, &(*temp)->sz_ln, &(*temp)->endian)))
			ft_exit(LOAD_SPECIAL_WALL);
		(*temp)->next = tex_init((*temp), NULL);
		(*temp) = (*temp)->next;
	}
}

void			load_texture(char *arr_id_tex, t_env **env)
{
	int			i;
	char		*tex;
	t_tex		*temp;

	i = -1;
	(*env)->tex = tex_init(NULL, NULL);
	temp = (*env)->tex;
	while (arr_id_tex[++i])
	{
		tex = get_texture_name(i, arr_id_tex);
		if (ft_strcmp(tex, SPECIAL_WALL) == 0)
			load_special_wall(tex, &temp, env);
		else
		{
			if (!(temp->tex_ptr = mlx_xpm_file_to_image((*env)->mlx,
				tex, &temp->width, &temp->height)))
				ft_exit(LOAD_TEXTURE);
			if (!(temp->data = mlx_get_data_addr(temp->tex_ptr,
				&temp->bts_pr_px, &temp->sz_ln, &temp->endian)))
				ft_exit(LOAD_TEXTURE);
			temp->id = arr_id_tex[i];
			temp->next = tex_init(temp, NULL);
			temp = temp->next;
		}
	}
}

void			load_textures(t_env *env)
{
	char		*arr_id_tex;

	arr_id_tex = ft_strnew(NBR_TEXTURES);
	get_arr_text_id(arr_id_tex, env);
	load_texture(arr_id_tex, &env);
	ft_strdel(&arr_id_tex);
}
