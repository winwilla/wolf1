/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 10:27:05 by memelia           #+#    #+#             */
/*   Updated: 2019/11/12 12:53:26 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t	i;
	char	*str1;
	char	*str2;

	if (!s1 && !s2)
		return (1);
	else if (!s1 || !s2)
		return (0);
	else
	{
		i = 0;
		str1 = (char *)s1;
		str2 = (char *)s2;
		if (str1 && str2)
		{
			if (ft_strncmp(str1, str2, n) == 0)
				return (1);
		}
	}
	return (0);
}
