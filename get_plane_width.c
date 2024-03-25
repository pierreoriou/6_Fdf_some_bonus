/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:07:31 by peoriou           #+#    #+#             */
/*   Updated: 2024/03/25 17:17:10 by poriou           ###   ########.fr       */
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

	if (map->grid->width == 1 && map->grid->len == 1)
		return (100);
	grid_len_width = map->plane->vect_x->scale * map->grid->len;
	grid_len_width *= sin(map->plane->rotate_z * M_PI / 180);
	grid_width_width = map->plane->vect_y->scale * map->grid->width;
	grid_width_width *= cos(map->plane->rotate_z * M_PI / 180);
	res = grid_len_width + grid_width_width;
	while (res > 1920 && map->plane->scale_x > 3)
	{
		reduce_scales(&(map->plane));
		if ()
		res = upd_plane_width(map);

	}
	return (res);
}
