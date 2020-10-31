/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 17:09:55 by memelia           #+#    #+#             */
/*   Updated: 2019/11/12 12:53:17 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int			ft_getnbr(char *str)
{
	int		i;
	int		nbr;
	int		key;

	i = 0;
	key = 1;
	nbr = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			key = -1;
		i++;
	}
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		nbr = (nbr * 10) + (str[i] - '0');
		i++;
	}
	return (key * nbr);
}
