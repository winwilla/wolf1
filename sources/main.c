/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 23:54:35 by memelia           #+#    #+#             */
/*   Updated: 2020/05/17 23:55:04 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int			main(int argc, char **argv)
{
	t_env	*env;

	if (argc > 1)
		ft_exit(ERROR_INPUT);
	env = env_init();
	load_menu_data(env);
	load_settings_data(env);
	load_chooser_data(env);
	load_weapon_texture(env);
	change_music(music_flag_0, env->music);
	draw_main_menu(env);
	init_key_hooks(env);
	mlx_loop(env->mlx);
	return (0);
}
