/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 23:59:26 by memelia           #+#    #+#             */
/*   Updated: 2020/05/18 00:00:08 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		mouse_scroll(int x, int y, int button, t_env *env)
{
	int temp;
	int sign;

	temp = env->menu->controls->s_pos;
	if (button == 4)
		env->menu->controls->s_pos += 8;
	if (button == 5)
		env->menu->controls->s_pos -= 8;
	if (temp < env->menu->controls->s_pos)
		sign = 1;
	else if (temp > env->menu->controls->s_pos)
		sign = 0;
	if (env->menu->controls->s_pos < 79)
		env->menu->controls->s_pos = 79;
	if (env->menu->controls->s_pos > 842)
		env->menu->controls->s_pos = 842;
	if (temp != env->menu->controls->s_pos)
		scrolling(env, sign, temp);
	check_card_selection(x, y, env);
	draw_chooser(env);
}

int			push_buttons(int button, int x, int y, t_env *env)
{
	if (button == 1 && env->mode == Game)
		playSound(SHOT, env->volume);
	if (env->mode == Menu && button == 1)
		menu_push_buttons(x, y, env);
	if (env->mode == Settings && button == 1)
		settings_push_buttons(x, y, env);
	if (env->mode == Choose && button == 1)
		push_scroller(x, y, env);
	if (env->mode == Choose && (button == 4 || button == 5)
		&& env->menu->controls->scroller_status)
		mouse_scroll(x, y, button, env);
	return (0);
}

int			mouse_move(int x, int y, t_env *env)
{
	if (env->mode == Menu)
		menu_controls(x, y, env);
	if (env->mode == Settings)
		settings_controls(x, y, env);
	if (env->mode == Choose)
		chooser_controls(x, y, env);
	if (env->mode == Game)
	{
		env->cam->view_height = (y - (HEIGHT >> 1)) * 3;
		renderer(env);
	}
	return (0);
}

int			mouse_release(int button, int x, int y, t_env *env)
{
	if (button == 1)
	{
		env->menu->controls->pressed[0] = 0;
		env->menu->controls->pressed[1] = 0;
		env->menu->controls->pressed[2] = 0;
		env->menu->controls->pressed[3] = 0;
		env->menu->controls->pressed[4] = 0;
	}
	return (0);
}
