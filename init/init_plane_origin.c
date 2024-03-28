/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane_origin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:28:17 by poriou            #+#    #+#             */
/*   Updated: 2024/03/28 10:32:06 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int	find_y_origin(t_map *map)
{
	int	peak_y;
	int	half_plane_height;

	peak_y = map->grid->max_z * map->plane->vect_z->scale;
	peak_y *= cos(map->plane->rotate_y * M_PI / 180);
	half_plane_height = (map->grid->len - 1) * map->plane->vect_x->scale;
	half_plane_height *= sin(map->plane->rotate_y * M_PI / 180);
	return (peak_y + half_plane_height + map->plane->margin_y);
}

t_pixel	*init_plane_origin(t_map *map)
{
	t_pixel	*origin;

	origin = init_pixel(map);
	origin->x = map->plane->margin_x;
	origin->y = find_y_origin(map);
	return (origin);
}
