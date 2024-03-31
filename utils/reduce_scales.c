/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_scales.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 11:46:11 by poriou            #+#    #+#             */
/*   Updated: 2024/03/31 20:37:59 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	reduce_scales(t_plane *plane)
{
	if (plane->vect_x->scale == 3
		|| plane->vect_y->scale == 3
		|| plane->vect_z->scale == 3)
		return ;
	plane->vect_x->scale--;
	plane->vect_y->scale--;
	plane->vect_z->scale--;
}
