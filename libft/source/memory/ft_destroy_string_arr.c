/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_string_arr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 19:38:56 by memelia           #+#    #+#             */
/*   Updated: 2020/01/15 21:51:43 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void		ft_destroy_string_arr(char **arr)
{
	int		i;

	i = -1;
	if (arr && arr[0])
	{
		while (arr[++i])
			;
		while (--i >= 0)
		{
			free(arr[i]);
			arr[i] = NULL;
		}
		free(arr);
		arr = NULL;
	}
	else if (arr)
	{
		free(arr);
		arr = NULL;
	}
}
