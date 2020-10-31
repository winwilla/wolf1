/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_caster.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/18 00:03:04 by memelia           #+#    #+#             */
/*   Updated: 2020/05/18 00:03:39 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		set_values(t_ray *ray, t_cast *cast, t_cam *cam, int *wall_hit)
{
	*wall_hit = No;
	cast->distance = 0;
	ray->m_pos[X] = (int)cam->pos[X];
	ray->m_pos[Y] = (int)cam->pos[Y];
	ray->d_dist[H] = sqrt(pow(ray->v_dir[Y], 2.0) /
		pow(ray->v_dir[X], 2.0) + 1);
	ray->d_dist[V] = sqrt(pow(ray->v_dir[X], 2.0) /
		pow(ray->v_dir[Y], 2.0) + 1);
	cast->step[X] = (ray->v_dir[X] < 0 ? -1 : 1);
	cast->step[Y] = (ray->v_dir[Y] < 0 ? -1 : 1);
	ray->s_dist[H] = (cast->step[X] > 0
		? ray->m_pos[X] - cam->pos[X] + 1
		: cam->pos[X] - ray->m_pos[X]) * ray->d_dist[H];
	ray->s_dist[V] = (cast->step[Y] > 0
		? ray->m_pos[Y] - cam->pos[Y] + 1
		: cam->pos[Y] - ray->m_pos[Y]) * ray->d_dist[V];
}

static void		wall_search(t_ray *ray, t_cast *cast, t_env *env, int *wall_hit)
{
	while (*wall_hit == No)
	{
		if (ray->s_dist[H] < ray->s_dist[V])
		{
			ray->s_dist[H] += ray->d_dist[H];
			ray->m_pos[X] += cast->step[X];
			ray->side = H;
		}
		else
		{
			ray->s_dist[V] += ray->d_dist[V];
			ray->m_pos[Y] += cast->step[Y];
			ray->side = V;
		}
		if (env->map->level[ray->m_pos[Y]][ray->m_pos[X]] > '0')
			*wall_hit = Yes;
	}
}

void			cast_a_ray(t_cast *cast, t_cam *cam, t_env *env)
{
	int			wall_hit;

	set_values(cast->ray, cast, cam, &wall_hit);
	wall_search(cast->ray, cast, env, &wall_hit);
	if (wall_hit == Yes)
	{
		cast->distance = (cast->ray->side == H
			? (cast->ray->m_pos[X] - cam->pos[X]
				+ (1 - cast->step[X]) / 2) / cast->ray->v_dir[X]
			: (cast->ray->m_pos[Y] - cam->pos[Y] +
				(1 - cast->step[Y]) / 2) / cast->ray->v_dir[Y]);
		cast->wall_height = (int)floor(HEIGHT * 1.27 / cast->distance);
	}
}
