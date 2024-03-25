/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:07:32 by poriou            #+#    #+#             */
/*   Updated: 2024/03/25 17:28:00 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_plane(t_map *map)
{
	map->plane = init_plane(map);
	upd_pixels_new_scale(map);
	map->plane->vect_x = init_vect_x(map);
	map->plane->vect_y = init_vect_y(map);
	map->plane->vect_z = init_vect_z(map);
	map->plane->initial_angle_x = 90;
	map->plane->initial_angle_y = 0;
	map->plane->initial_angle_z = 0;
	map->plane->rotate_z = find_optimal_vert_rotation(map);
	map->plane->rotate_y = find_horiz_rotation(map);
	map->plane->width = get_plane_width(map);
	map->plane->height = get_plane_height(map);
	map->plane->origin = init_plane_origin(map);
	// map->plane->margin_x = get_plane_margin_x(map);
	// map->plane->margin_y = get_plane_margin_y(map);
	// map->plane->origin = get_plane_origin(map);
	print_plane(map->plane, "in create plane :");
}
