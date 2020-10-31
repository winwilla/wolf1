/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chooser_scroller.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 23:46:42 by memelia           #+#    #+#             */
/*   Updated: 2020/05/17 23:47:18 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		resset_card_coords(t_env *env)
{
	while (env->menu->cards->id != 0)
		env->menu->cards = env->menu->cards->prev;
	env->menu->cards->pos = 79;
	while (env->menu->cards->id < env->menu->controls->num_of_cards)
	{
		if (!env->menu->cards->next)
			break ;
		env->menu->cards = env->menu->cards->next;
		env->menu->cards->pos = env->menu->cards->prev->pos + 106;
	}
}

void		scrolling(t_env *env, char sign, int old_value)
{
	while (env->menu->cards->id != 0)
		env->menu->cards = env->menu->cards->prev;
	while (env->menu->cards->id < env->menu->controls->num_of_cards)
	{
		if (sign == 0)
			env->menu->cards->pos -= (env->menu->controls->s_pos - old_value) *
				ceil(env->menu->controls->num_of_cards / 7);
		else if (sign == 1)
			env->menu->cards->pos += (old_value - env->menu->controls->s_pos) *
				ceil(env->menu->controls->num_of_cards / 7);
		if (!env->menu->cards->next)
			break ;
		env->menu->cards = env->menu->cards->next;
	}
}

void		move_scroller(int y, t_env *env)
{
	int		temp;
	char	sign;

	temp = env->menu->controls->s_pos;
	env->menu->controls->s_pos = y - 30;
	if (temp < env->menu->controls->s_pos)
		sign = 1;
	else if (temp > env->menu->controls->s_pos)
		sign = 0;
	if (y < 79 + 30)
		env->menu->controls->s_pos = 79;
	if (y > 842 + 30)
		env->menu->controls->s_pos = 842;
	if (temp != env->menu->controls->s_pos)
		scrolling(env, sign, temp);
}

void		push_scroller(int x, int y, t_env *env)
{
	char	*map_loc;

	check_push_add_buttons(x, y, env);
	if (x >= WIDTH - 100 && x <= WIDTH - 78 &&
		y >= env->menu->controls->s_pos &&
			y <= env->menu->controls->s_pos + 73 &&
				env->menu->controls->scroller_status == 1)
		env->menu->controls->pressed[4] = Yes;
	if (env->menu->controls->num_of_cards > 0)
		if (env->menu->cards->selected == Yes)
		{
			if (!(map_loc = ft_strdup(MAPS_FOLDER)))
				ft_exit(PUSH_SCROLLER);
			if (!(map_loc = ft_strjoin_free(map_loc,
				env->menu->cards->level_name, 1)))
				ft_exit(PUSH_SCROLLER);
			check_validation(map_loc, env);
			if (map_loc)
				free(map_loc);
		}
}
