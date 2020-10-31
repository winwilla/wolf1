/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arr_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 01:49:39 by memelia           #+#    #+#             */
/*   Updated: 2019/12/05 17:38:46 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

void	print_arr_str(char **arr_str)
{
	int	i;

	i = -1;
	if (!arr_str || !*arr_str)
	{
		ft_putendl("NO ARRAY!");
		return ;
	}
	while (arr_str[++i])
	{
		ft_putstr(arr_str[i]);
		ft_putchar(' ');
	}
}
