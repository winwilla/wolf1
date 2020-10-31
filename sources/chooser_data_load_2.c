/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chooser_data_load_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 23:43:50 by memelia           #+#    #+#             */
/*   Updated: 2020/05/17 23:44:35 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			create_background(t_env *env, t_lvl_crd *card)
{
	int x;
	int y;

	y = -1;
	card->background = tex_init(NULL, NULL);
	if (!(card->background->tex_ptr = mlx_new_image(env->mlx, 1324, 72)))
		ft_exit(CREATE_BACKGROUND);
	card->background->data = mlx_get_data_addr(card->background->tex_ptr,
		&card->background->bts_pr_px, &card->background->sz_ln,
		&card->background->endian);
	while (++y < 72)
	{
		x = -1;
		while (++x < 1324)
			((int *)card->background->data)[y * 1324 + x] = 0x55B7B7B7;
	}
}
