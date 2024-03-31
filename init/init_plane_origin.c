/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane_origin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:28:17 by poriou            #+#    #+#             */
/*   Updated: 2024/03/31 20:41:25 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	find_y_origin(t_map *map)
{
	int	max;
	int	half_plane_height;
	int	depth;

	depth = 0;
	max = map->plane->height + map->plane->margin_y;
	if (map->grid->min_z < 0)
	{
		depth = map->plane->vect_z->y_in_plane * map->grid->min_z;
		depth *= -1;
	}
	half_plane_height = (map->grid->width - 1) * map->plane->vect_y->y_in_plane;
	half_plane_height *= -1;
	return (max - half_plane_height - depth);
}

t_pixel	*init_plane_origin(t_map *map)
{
	t_pixel	*origin;

	origin = init_pixel_origin(map);
	origin->x = map->plane->margin_x;
	origin->y = find_y_origin(map);
	return (origin);
}
