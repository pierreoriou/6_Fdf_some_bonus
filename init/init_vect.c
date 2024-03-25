/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:08:45 by peoriou           #+#    #+#             */
/*   Updated: 2024/03/25 17:00:22 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_vect	*init_vect_x(t_map *map)
{
	t_vect	*vect_x;

	vect_x = (t_vect *)malloc(sizeof(t_vect));
	if (!vect_x)
		free_close_exit(map, NULL, "Problem allocating memory.");
	vect_x->scale = 10;
	vect_x->x_in_plane = 0;
	vect_x->y_in_plane = vect_x->scale_x;
	return (vect_x);
}

t_vect	*init_vect_y(t_map *map)
{
	t_vect	*vect_y;

	vect_y = (t_vect *)malloc(sizeof(t_vect));
	if (!vect_y)
		free_close_exit(map, NULL, "Problem allocating memory.");
	vect_y->scale = 10;
	vect_y->x_in_plane = vect_y->scale;
	vect_y->y_in_plane = 0;
	return (vect_y);
}

t_vect	*init_vect_z(t_map *map)
{
	t_vect	*vect_z;

	vect_z = (t_vect *)malloc(sizeof(t_vect));
	if (!vect_z)
		free_close_exit(map, NULL, "Problem allocating memory.");
	vect_z->scale = 10;
	vect_z->x_in_plane = 0;
	vect_z->y_in_plane = 0;
	return (vect_z);
}
