/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:08:45 by peoriou           #+#    #+#             */
/*   Updated: 2024/03/22 17:55:26 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_vect	*init_vect_x(t_map *map)
{
	t_vect	*vect_x;

	vect_x = (t_vect *)malloc(sizeof(t_vect));
	if (!vect_x)
		free_close_exit(map, NULL, "Problem allocating memory.");
	vect_x->x = map->plane->scale_x;
	vect_x->y = 0;
	vect_x->z = 0;
	// vect_x->x_angle = 0;
	// vect_x->y_angle = 90;
	// vect_x->z_angle = 0;
	vect_x->horiz_angle = 90;
	vect_x->vertic_angle = 270;
	return (vect_x);
}

t_vect	*init_vect_y(t_map *map)
{
	t_vect	*vect_y;

	vect_y = (t_vect *)malloc(sizeof(t_vect));
	if (!vect_y)
		free_close_exit(map, NULL, "Problem allocating memory.");
	vect_y->x = 0;
	vect_y->y = map->plane->scale_y;
	vect_y->z = 0;
	// vect_y->x_angle = 270;
	// vect_y->y_angle = 0;
	// vect_y->z_angle = 0;
	vect_y->horiz_angle = 0;
	vect_y->vertic_angle = 270;
	return (vect_y);
}

t_vect	*init_vect_z(t_map *map)
{
	t_vect	*vect_z;

	vect_z = (t_vect *)malloc(sizeof(t_vect));
	if (!vect_z)
		free_close_exit(map, NULL, "Problem allocating memory.");
	vect_z->x = 0;
	vect_z->y = 0;
	vect_z->z = map->plane->scale_z;
	// vect_z->x_angle = 0;
	// vect_z->y_angle = 90;
	// vect_z->z_angle = 90;
	vect_z->horiz_angle = 90;
	vect_z->vertic_angle = 0;
	return (vect_z);
}
