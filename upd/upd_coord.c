/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upd_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 11:36:16 by poriou            #+#    #+#             */
/*   Updated: 2024/03/28 12:20:43 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	upd_coord_pixel_y(t_plane *plane, t_coord *coord)
{
	coord->pixel->y = plane->origin->y - (coord->x * plane->vect_x->y_in_plane);
	coord->pixel->y -= coord->y * plane->vect_y->y_in_plane;
	coord->pixel->y -= coord->z * plane->vect_z->y_in_plane;
}

static void	upd_coord_pixel_x(t_plane *plane, t_coord *coord)
{
	coord->pixel->x = plane->origin->x + (coord->x * plane->vect_x->x_in_plane);
	coord->pixel->x += coord->y * plane->vect_y->x_in_plane;
}

void	upd_coord(t_plane *plane, t_coord *coord)
{
	while (coord)
	{
		upd_coord_pixel_x(plane, coord);
		upd_coord_pixel_y(plane, coord);
		coord = coord->next;
	}
}
