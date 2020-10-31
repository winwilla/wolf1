/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 14:18:35 by memelia           #+#    #+#             */
/*   Updated: 2019/11/12 12:53:16 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int		ft_atoi(const char *str)
{
	long int	previous;
	long int	nb;
	int			key;

	nb = 0;
	key = 1;
	while (*str == '\n' || *str == '\t' || *str == '\r'
		|| *str == ' ' || *str == '\v' || *str == '\f')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			key = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		previous = nb;
		nb = nb * 10 + (*str++ - '0');
		if (previous > nb)
			return (key == -1 ? 0 : -1);
	}
	return (key * (int)nb);
}
