/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chooser.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 23:47:40 by memelia           #+#    #+#             */
/*   Updated: 2020/05/17 23:48:11 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_base_n_scroller(t_env *env)
{
	mlx_put_image_to_window(env->mlx, env->win,
		env->menu->chooser->tex_ptr, (WIDTH - 89), 79);
	mlx_put_image_to_window(env->mlx, env->win,
		env->menu->chooser->prev->tex_ptr, WIDTH - 100,
		env->menu->controls->s_pos);
}

void	draw_cards(t_env *env, t_lvl_crd *cards)
{
	while (cards->id != env->menu->controls->id_first_card)
		cards = cards->prev;
	while (1)
	{
		if (cards->pos < HEIGHT)
		{
			mlx_put_image_to_window(env->mlx, env->win,
				cards->background->tex_ptr, 243, cards->pos);
			mlx_string_put(env->mlx, env->win, 258,
				cards->pos + 23, cards->font_color, cards->level_name);
		}
		if (cards->next)
			cards = cards->next;
		else
			break ;
	}
}

void	draw_chooser(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	mlx_put_image_to_window(env->mlx, env->win,
		env->menu->first_tex[Menu]->tex_ptr, env->menu->bg_off[X],
		env->menu->bg_off[Y]);
	if (env->menu->controls->scroller_status)
		draw_base_n_scroller(env);
	if (env->menu->controls->num_of_cards > 0)
		draw_cards(env, env->menu->cards);
	draw_add_buttons(env);
}
