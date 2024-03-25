/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:07:32 by poriou            #+#    #+#             */
/*   Updated: 2024/03/25 13:56:26 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_plane(t_map *map)
{
	map->plane = init_plane(map);
	init_scales_to_10(map->plane);
	map->plane->initial_angle_x = 90;
	map->plane->initial_angle_y = 0;
	map->plane->initial_angle_z = 0;
	map->plane->rotate_z = find_optimal_vert_rotation(map);
	map->plane->vect_x = init_vect_x(map);
	map->plane->vect_y = init_vect_y(map);
	map->plane->vect_z = init_vect_z(map);
	map->plane->width = get_plane_width(map);
	map->plane->height = get_plane_height(map);
	print_plane(map->plane, "in create plane :");
}
