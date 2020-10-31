/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 18:59:24 by memelia           #+#    #+#             */
/*   Updated: 2019/11/12 12:48:35 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

void		*char_error(char *error_text, char *line_for_free)
{
	ft_putstr("\033[31m");
	ft_putendl(error_text);
	if (line_for_free)
		ft_strdel(&line_for_free);
	return (NULL);
}
