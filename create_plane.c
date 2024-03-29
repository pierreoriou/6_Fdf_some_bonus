/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:07:32 by poriou            #+#    #+#             */
/*   Updated: 2024/03/29 16:10:29 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	create_plane(t_map *map)
{
	map->plane = init_plane(map);
	map->plane->vect_x = init_vect_x(map);
	map->plane->vect_y = init_vect_y(map);
	map->plane->vect_z = init_vect_z(map);
	map->plane->rotate_z = find_optimal_vert_rotation(map);
	map->plane->rotate_y = find_horiz_rotation(map);
	upd_vectors(map);
	map->plane->width = get_plane_width(map);
	map->plane->height = get_plane_height(map);
	map->plane->width = upd_plane_width(map);
	map->plane->margin_x = get_plane_margin_x(map);
	map->plane->margin_y = get_plane_margin_y(map);
	map->plane->origin = init_plane_origin(map);
}
