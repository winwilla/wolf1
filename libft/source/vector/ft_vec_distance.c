/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vec_distance.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 12:42:17 by memelia           #+#    #+#             */
/*   Updated: 2019/11/12 12:47:52 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"

double		ft_vec_distance(t_vector a, t_vector b)
{
	double	distance;

	distance = sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y)
	+ (a.z - b.z) * (a.z - b.z));
	return (distance);
}
