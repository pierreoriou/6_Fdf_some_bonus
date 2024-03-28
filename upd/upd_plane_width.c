/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upd_plane_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 10:40:38 by poriou            #+#    #+#             */
/*   Updated: 2024/03/28 11:28:28 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	upd_plane_width(t_map *map)
{
	int	res;
	int	grid_len_width;
	int	grid_width_width;

	grid_len_width = map->plane->vect_x->scale * (map->grid->len - 1);
	grid_len_width *= sin(map->plane->rotate_z * M_PI / 180);
	grid_width_width = map->plane->vect_y->scale * (map->grid->width - 1);
	grid_width_width *= cos(map->plane->rotate_z * M_PI / 180);
	res = grid_len_width + grid_width_width;
	if (res < 100)
		return (100);
	return (res);
}
