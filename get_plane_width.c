/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:07:31 by peoriou           #+#    #+#             */
/*   Updated: 2024/03/29 16:04:09 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_plane_width(t_map *map)
{
	int	res;

	if (map->grid->width == 1 && map->grid->len == 1)
		return (100);
	res = upd_plane_width(map);
	while (res > 1920 && map->plane->vect_x->scale > 3)
	{
		reduce_scales(map->plane);
		upd_vectors(map);
		res = upd_plane_width(map);
	}
	if (res < 100)
		return (100);
	return (res);
}
