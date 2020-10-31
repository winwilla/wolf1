/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 10:58:38 by memelia           #+#    #+#             */
/*   Updated: 2019/11/16 04:17:30 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static int			ft_counter_i(char const *s)
{
	int		i;

	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
	{
		if (!(s[i + 1]))
			return (-1);
		++i;
	}
	return (i);
}

char				*ft_strtrim(char const *s)
{
	char		*str;
	int			i;
	int			j;
	int			k;

	if (!s)
		return ((char *)s);
	i = ft_counter_i(s);
	if (i < 0)
		return (ft_strnew(0));
	j = 0;
	k = ft_strlen(s) - 1;
	while (s[k] == ' ' || s[k] == '\n' || s[k] == '\t')
		k--;
	str = (char *)ft_safe_malloc(sizeof(char) * (k - i + 2));
	while (i <= k)
		str[j++] = s[i++];
	str[j] = '\0';
	return (str);
}
