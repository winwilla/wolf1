/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 06:43:32 by memelia           #+#    #+#             */
/*   Updated: 2019/11/12 12:53:23 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t k;
	size_t len;

	if (!dst && !src)
		return (0);
	i = 0;
	k = 0;
	len = ft_strlen(src);
	while (dst[i] && i < size)
		i++;
	if (size > 0)
	{
		while (src[k] && i < size - 1)
		{
			dst[i++] = src[k++];
		}
	}
	if (k > 0)
	{
		dst[i] = '\0';
		return (len + i - k);
	}
	return (len + i);
}
