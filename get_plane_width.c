/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:07:31 by peoriou           #+#    #+#             */
/*   Updated: 2024/03/23 11:16:51 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	upd_plane_width(t_map *map)
{
	int	res;
	int	grid_len_width;
	int	grid_width_width;

	grid_len_width = map->plane->scale_x * map->grid->len;
	grid_len_width *= cos(map->plane->rotate_z * M_PI / 180);
	grid_width_width = map->plane->scale_y * map->grid->width;
	grid_width_width *= cos(map->plane->rotate_z * M_PI / 180);
	res = grid_len_width + grid_width_width;
	return (res);
}

int	get_plane_width(t_map *map)
{
	int	res;
	int	grid_len_width;
	int	grid_width_width;

	grid_len_width = map->plane->scale_x * map->grid->len;
	grid_len_width *= cos(map->plane->rotate_z * M_PI / 180);
	grid_width_width = map->plane->scale_y * map->grid->width;
	grid_width_width *= cos(map->plane->rotate_z * M_PI / 180);
	res = grid_len_width + grid_width_width;
	while (res > 1920 && map->plane->scale_x > 3)
	{
		reduce_scales(&(map->plane));
		res = upd_plane_width(map);
	}
	return (res);
}
