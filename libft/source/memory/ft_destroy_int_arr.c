/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_int_arr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 19:38:56 by memelia           #+#    #+#             */
/*   Updated: 2020/01/15 22:09:30 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void			ft_destroy_int_arr(int **arr, int i)
{
	while (i >= 0)
	{
		ft_memdel((void *)arr[i]);
		i--;
	}
	ft_memdel((void *)arr);
}
