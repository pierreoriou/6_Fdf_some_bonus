/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:07:32 by poriou            #+#    #+#             */
/*   Updated: 2024/03/22 13:47:52 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

int	upd_plane_width(t_map *map)
{
	int	res;
	int	grid_len_width;
	int	grid_width_width;

	grid_len_width = map->plane->scale_x * map->grid.len;
	grid_len_width *= cos(map->plane->rotate_z * M_PI / 180);
	grid_width_width = map->plane->scale_y * map->grid.width;
	grid_width_width *= cos(map->plane->rotate_z * M_PI / 180);
	res = grid_len_width + grid_width_width;
	return (res);
}

int	upd_plane_height(t_map *map)
{
	int	res;
	int	grid_len_height;
	int	grid_width_height;
	int	altitude;

	grid_len_height = map->plane->scale_x * map->grid.len;
	grid_len_height *= sin(map->plane->rotate_y * M_PI / 180);
	grid_width_height = map->plane->scale_y * map->grid.width;
	grid_width_height *= sin(map->plane->rotate_y * M_PI / 180);
	altitude = map->plane->scale_z * map->grid.max_z;
	res = grid_len_height + grid_width_height + altitude;
	return (res);
}

int	get_plane_width(t_map *map)
{
	int	res;
	int	grid_len_width;
	int	grid_width_width;

	grid_len_width = map->plane->scale_x * map->grid.len;
	grid_len_width *= cos(map->plane->rotate_z * M_PI / 180);
	grid_width_width = map->plane->scale_y * map->grid.width;
	grid_width_width *= cos(map->plane->rotate_z * M_PI / 180);
	res = grid_len_width + grid_width_width;
	while (res > 1920 && map->plane->scale_x > 3)
	{
		reduce_scales(&(map->plane));
		res = upd_plane_width(map);
	}
	return (res);
}

int	get_plane_height(t_map *map)
{
	int	res;
	int	grid_len_height;
	int	grid_width_height;
	int	altitude;

	grid_len_height = map->plane->scale_x * map->grid.len;
	grid_len_height *= sin(map->plane->rotate_y * M_PI / 180);
	grid_width_height = map->plane->scale_y * map->grid.width;
	grid_width_height *= sin(map->plane->rotate_y * M_PI / 180);
	altitude = map->plane->scale_z * map->grid.max_z;
	res = grid_len_height + grid_width_height + altitude;
	while (res > 1920 && map->plane->scale_x > 3)
	{
		reduce_scales(&(map->plane));
		res = upd_plane_height(map);
	}
	return (res);
}

void	create_plane(t_map *map)
{
	map->plane = init_plane(map);
	map->plane->vect_x = init_vect_x(map);
	init_scales_to_10(map->plane);
	init_rotations_to_30(map->plane);
	map->plane->width = get_plane_width(map);
	map->plane->height = get_plane_height(map);
	print_plane(map->plane, "in create plane");
}
