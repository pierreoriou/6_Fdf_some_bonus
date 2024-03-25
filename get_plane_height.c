/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane_height.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:10:27 by peoriou           #+#    #+#             */
/*   Updated: 2024/03/23 11:17:06 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	upd_plane_height(t_map *map)
{
	int	res;
	int	grid_len_height;
	int	grid_width_height;
	int	altitude;

	grid_len_height = map->plane->scale_x * map->grid->len;
	grid_len_height *= sin(map->plane->rotate_y * M_PI / 180);
	grid_width_height = map->plane->scale_y * map->grid->width;
	grid_width_height *= sin(map->plane->rotate_y * M_PI / 180);
	altitude = map->plane->scale_z * map->grid->max_z;
	res = grid_len_height + grid_width_height + altitude;
	return (res);
}

int	get_plane_height(t_map *map)
{
	int	res;
	int	grid_len_height;
	int	grid_width_height;
	int	altitude;

	grid_len_height = map->plane->scale_x * map->grid->len;
	grid_len_height *= sin(map->plane->rotate_y * M_PI / 180);
	grid_width_height = map->plane->scale_y * map->grid->width;
	grid_width_height *= sin(map->plane->rotate_y * M_PI / 180);
	altitude = map->plane->scale_z * map->grid->max_z;
	res = grid_len_height + grid_width_height + altitude;
	while (res > 1920 && map->plane->scale_x > 3)
	{
		reduce_scales(&(map->plane));
		res = upd_plane_height(map);
	}
	return (res);
}
