/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chooser_data_load.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 23:44:28 by memelia           #+#    #+#             */
/*   Updated: 2020/05/17 23:45:05 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static t_lvl_crd	*create_card(t_env *env, int id,
						const char *file_name, t_lvl_crd *prev)
{
	t_lvl_crd *new_card;

	new_card = (t_lvl_crd *)ft_safe_malloc(sizeof(t_lvl_crd));
	new_card->id = id;
	if (!(new_card->level_name = ft_strdup(file_name)))
		ft_exit(CREATE_CARD);
	if (prev)
		new_card->pos = prev->pos + 106;
	else
		new_card->pos = 79;
	new_card->prev = prev;
	new_card->next = NULL;
	create_background(env, new_card);
	new_card->font_color = 0x575757;
	new_card->selected = No;
	return (new_card);
}

static void			check_file_name(t_env *env, t_menu *menu, int *id)
{
	int len;

	if ((len = ft_strlen(menu->file_name->d_name)) < 3)
		return ;
	if (menu->file_name->d_name[len - 3] == '.' &&
		menu->file_name->d_name[len - 2] == 'w' &&
		menu->file_name->d_name[len - 1] == 'm')
	{
		if (!menu->cards)
			menu->cards = create_card(env, ++(*id),
				menu->file_name->d_name, menu->cards);
		else
		{
			menu->cards->next = create_card(env, ++(*id),
				menu->file_name->d_name, menu->cards);
			menu->cards = menu->cards->next;
		}
	}
}

void				read_map_files(t_env *env, t_menu *menu)
{
	int ct;
	int id;

	ct = -1;
	id = -1;
	if (!(menu->dir_ptr = opendir(MAPS_FOLDER)))
		ft_exit(READ_MAP_FILES);
	while (++ct < MAPS_LIMIT + 2)
	{
		if ((menu->file_name = readdir(menu->dir_ptr)))
			check_file_name(env, menu, &id);
		else
			break ;
	}
	menu->controls->num_of_cards = id + 1;
	closedir(menu->dir_ptr);
	menu->dir_ptr = NULL;
}

void				load_scroller(t_env *env)
{
	int ct;

	ct = -1;
	if (!(env->menu->chooser->tex_ptr = mlx_xpm_file_to_image(env->mlx,
	SCRL, &env->menu->chooser->width, &env->menu->chooser->height)))
		ft_exit(LOAD_SCROLLER);
	env->menu->chooser->data = mlx_get_data_addr(env->menu->chooser->tex_ptr,
		&env->menu->chooser->bts_pr_px, &env->menu->chooser->sz_ln,
		&env->menu->chooser->endian);
	env->menu->chooser->id = 'S';
	env->menu->chooser->next = tex_init(env->menu->chooser, NULL);
	env->menu->chooser = env->menu->chooser->next;
	if (!(env->menu->chooser->tex_ptr = mlx_new_image(env->mlx, 1, 835)))
		ft_exit(LOAD_SCROLLER);
	env->menu->chooser->data = mlx_get_data_addr(env->menu->chooser->tex_ptr,
		&env->menu->chooser->bts_pr_px, &env->menu->chooser->sz_ln,
		&env->menu->chooser->endian);
	env->menu->chooser->id = 'B';
	while (++ct < 835)
		((int *)env->menu->chooser->data)[ct] = 0xCDFFFFFF;
}

void				load_chooser_data(t_env *env)
{
	load_scroller(env);
	env->menu->controls->id_first_card = 0;
	read_map_files(env, env->menu);
	if (env->menu->controls->num_of_cards > 9)
		env->menu->controls->scroller_status = 1;
	else
		env->menu->controls->scroller_status = 0;
}
