/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 23:48:31 by memelia           #+#    #+#             */
/*   Updated: 2020/05/17 23:48:56 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		x_close(t_env *env)
{
	Mix_FreeMusic(env->music[0]);
	Mix_FreeMusic(env->music[1]);
	Mix_FreeMusic(env->music[2]);
	Mix_FreeMusic(env->music[3]);
	SDL_Quit();
	(void)env;
	exit(0);
}
