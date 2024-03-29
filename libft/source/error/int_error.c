/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:59:01 by memelia           #+#    #+#             */
/*   Updated: 2019/11/26 05:41:30 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

int			int_error(char *error_text)
{
	ft_putstr("\033[31m");
	ft_putendl(error_text);
	ft_putstr("\033[0m");
	return (1);
}
