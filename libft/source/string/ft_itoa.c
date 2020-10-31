/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:55:53 by memelia           #+#    #+#             */
/*   Updated: 2019/11/16 04:16:43 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static int		ft_count(int nbr, int len)
{
	while (nbr / 10 != 0)
	{
		++len;
		nbr /= 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	dub;

	len = n < 0 ? 2 : 1;
	len = ft_count(n, len);
	dub = n < 0 ? -n : n;
	str = (char *)ft_safe_malloc(sizeof(char) * (len + 1));
	str[len--] = '\0';
	while (len >= 0)
	{
		n = dub % 10;
		str[len--] = n + '0';
		dub /= 10;
	}
	if (str[0] == '0' && str[1])
		str[0] = '-';
	return (str);
}
