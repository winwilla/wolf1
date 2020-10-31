/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 18:24:22 by memelia           #+#    #+#             */
/*   Updated: 2019/11/12 12:49:24 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"

void	ft_putnbr(int n)
{
	unsigned int	nbr;

	if (n < 0)
	{
		ft_putchar('-');
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr >= 10)
	{
		ft_putnbr(nbr / 10);
		ft_putchar((nbr % 10) + '0');
	}
	else
	{
		if (n > 0)
			ft_putchar(n + '0');
		else
			ft_putchar(-n + '0');
	}
}
