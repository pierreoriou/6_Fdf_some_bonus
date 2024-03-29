/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane_height.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:10:27 by peoriou           #+#    #+#             */
/*   Updated: 2024/03/29 16:29:02 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	upd_plane_height(t_map *map)
{
	int	grid_len_height;
	int	grid_width_height;
	int	altitude;
	int	depth;
	int	res;

	depth = 0;
	grid_len_height = map->plane->vect_x->y_in_plane * (map->grid->len - 1);
	grid_width_height = map->plane->vect_y->y_in_plane * (map->grid->width - 1);
	grid_width_height *= -1;
	altitude = map->plane->vect_z->y_in_plane * map->grid->max_z;
	if (map->grid->min_z < 0)
	{
		depth = map->plane->vect_z->y_in_plane * map->grid->min_z;
		depth *= -1;
	}
	res = grid_len_height + grid_width_height + altitude + depth;
	return (res);
}

int	get_plane_height(t_map *map)
{
	int	res;

	if (map->grid->width == 1 && map->grid->len == 1)
		return (100);
	res = upd_plane_height(map);
	while (res > 1050 && map->plane->vect_z->scale > 3)
	{
		reduce_scales(map->plane);
		upd_vectors(map);
		res = upd_plane_height(map);
	}
	if (res < 100)
		return (100);
	return (res);
}
