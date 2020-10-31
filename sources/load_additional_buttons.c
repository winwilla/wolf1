/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_additional_buttons.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 23:53:18 by memelia           #+#    #+#             */
/*   Updated: 2020/05/17 23:53:47 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	load_back_button(t_env *env)
{
	env->menu->back_button = tex_init(NULL, NULL);
	if (!(env->menu->back_button->tex_ptr = mlx_xpm_file_to_image(env->mlx,
	BCK_BTN, &env->menu->back_button->width, &env->menu->back_button->height)))
		ft_exit(LOAD_BACK_BUTTON);
	env->menu->back_button->data =
		mlx_get_data_addr(env->menu->back_button->tex_ptr,
		&env->menu->back_button->bts_pr_px, &env->menu->back_button->sz_ln,
		&env->menu->back_button->endian);
	env->menu->back_button->id = 'Z';
	env->menu->back_button->next = tex_init(env->menu->back_button, NULL);
	env->menu->back_button = env->menu->back_button->next;
	if (!(env->menu->back_button->tex_ptr = mlx_xpm_file_to_image(env->mlx,
	BCK_BTN, &env->menu->back_button->width, &env->menu->back_button->height)))
		ft_exit(LOAD_BACK_BUTTON);
	env->menu->back_button->data =
		mlx_get_data_addr(env->menu->back_button->tex_ptr,
		&env->menu->back_button->bts_pr_px, &env->menu->back_button->sz_ln,
		&env->menu->back_button->endian);
	env->menu->back_button->id = 'z';
	set_alpha(env->menu->back_button->data, env->menu->back_button->width,
		env->menu->back_button->height, BUTTONS_ALPHA);
}

void	load_refresh_button(t_env *env)
{
	env->menu->refresh_button = tex_init(NULL, NULL);
	if (!(env->menu->refresh_button->tex_ptr = mlx_xpm_file_to_image(env->mlx,
		RFSH_BTN, &env->menu->refresh_button->width,
			&env->menu->refresh_button->height)))
		ft_exit(LOAD_REFRESH_BUTTON);
	env->menu->refresh_button->data = mlx_get_data_addr(
		env->menu->refresh_button->tex_ptr,
		&env->menu->refresh_button->bts_pr_px,
		&env->menu->refresh_button->sz_ln, &env->menu->refresh_button->endian);
	env->menu->refresh_button->id = 'R';
	env->menu->refresh_button->next =
		tex_init(env->menu->refresh_button, NULL);
	env->menu->refresh_button = env->menu->refresh_button->next;
	if (!(env->menu->refresh_button->tex_ptr = mlx_xpm_file_to_image(env->mlx,
		RFSH_BTN, &env->menu->refresh_button->width,
		&env->menu->refresh_button->height)))
		ft_exit(LOAD_REFRESH_BUTTON);
	env->menu->refresh_button->data =
		mlx_get_data_addr(env->menu->refresh_button->tex_ptr,
		&env->menu->refresh_button->bts_pr_px,
		&env->menu->refresh_button->sz_ln, &env->menu->refresh_button->endian);
	env->menu->refresh_button->id = 'r';
	set_alpha(env->menu->refresh_button->data,
		env->menu->refresh_button->width,
		env->menu->refresh_button->height, BUTTONS_ALPHA);
}
