/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: memelia <memelia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 23:39:47 by memelia           #+#    #+#             */
/*   Updated: 2020/05/17 23:40:29 by memelia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROLS_H
# define CONTROLS_H

# define ESC 53

# define ARR_UP 126
# define ARR_DOWN 125
# define ARR_LFT 123
# define ARR_RGHT 124

# define KB_W 13
# define KB_A 0
# define KB_S 1
# define KB_D 2

# define SPACE 49

typedef struct	s_cntrls
{
	double		angle;
	int			old_coord[2];
}				t_cntrls;

#endif
