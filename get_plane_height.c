/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane_height.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:10:27 by peoriou           #+#    #+#             */
/*   Updated: 2024/03/28 11:27:14 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	upd_plane_height(t_map *map)
{
	int	res;
	int	grid_len_height;
	int	grid_width_height;
	int	altitude;

	grid_len_height = map->plane->vect_x->scale * (map->grid->len - 1);
	grid_len_height *= sin(map->plane->rotate_y * M_PI / 180);
	grid_width_height = map->plane->vect_y->scale * (map->grid->width - 1);
	grid_width_height *= sin(map->plane->rotate_y * M_PI / 180);
	altitude = map->plane->vect_z->scale * map->grid->max_z;
	altitude *= cos(map->plane->rotate_y * M_PI / 180);
	res = grid_len_height + grid_width_height + altitude;
	return (res);
}

int	get_plane_height(t_map *map)
{
	int	res;

	if (map->grid->width == 1 && map->grid->len == 1)
		return (100);
	res = upd_plane_height(map);
	while (res > 1920 && map->plane->vect_z->scale > 3)
	{
		reduce_scales(map->plane);
		res = upd_plane_height(map);
	}
	if (res < 100)
		return (100);
	return (res);
}
