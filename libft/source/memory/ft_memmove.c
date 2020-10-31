/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 15:17:19 by memelia           #+#    #+#             */
/*   Updated: 2019/11/16 04:18:30 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	ct;

	ct = -1;
	if (!dst && !src)
		return (NULL);
	if (dst < src)
		while (++ct < len)
			*(((unsigned char*)dst) + ct) = *(((unsigned char*)src) + ct);
	else
		while (len--)
			*(((unsigned char*)dst) + len) = *(((unsigned char*)src) + len);
	return (dst);
}
