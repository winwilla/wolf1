/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chooser_scroller_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 23:45:17 by memelia           #+#    #+#             */
/*   Updated: 2020/05/17 23:45:58 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	activate_game_mode(t_env *env)
{
	env->menu->cards->selected = No;
	env->menu->cards->font_color = 0x575757;
	change_bg_color(env->menu->cards, 0x55B7B7B7);
	load_textures(env);
	env->mode = Game;
	change_music(music_flag_1, env->music);
	renderer(env);
}

void		check_validation(const char *map_loc, t_env *env)
{
	t_map	*tmp;

	if (!(tmp = find_current_map(map_loc, &env->map)))
		ft_exit(CHECK_VALIDATION);
	if (!tmp->level)
	{
		if (!read_map(map_loc, tmp))
		{
			playSound(CHOOSER_ERROR, 128);
			system("osascript -e \'display notification\" \
This map is not valid!\" with title \"Warning!\"\'");
		}
		else
			activate_game_mode(env);
	}
	else
		activate_game_mode(env);
}
