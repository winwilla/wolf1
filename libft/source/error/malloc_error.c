/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:39:37 by memelia           #+#    #+#             */
/*   Updated: 2019/11/16 04:18:09 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

void		*malloc_error(char **arr)
{
	ft_putendl("\033[31mMalloc return null\033[0m");
	return (NULL);
}