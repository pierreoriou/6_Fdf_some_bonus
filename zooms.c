/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zooms.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:30:10 by poriou            #+#    #+#             */
/*   Updated: 2024/03/31 15:39:00 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_in(t_map *map)
{
	t_img	*im;

	im = map->image->img;
	map->plane->vect_x->scale++;
	map->plane->vect_y->scale++;
	map->plane->vect_z->scale++;
	upd_vectors(map);
	create_image(map);
	draw_in_image(map, map->coord, im);
	mlx_put_image_to_window(map->connect, map->connect->win_list, im, 0, 0);
}

void	zoom_out(t_map *map)
{
	t_img	*im;

	im = map->image->img;
	if (map->plane->vect_x->scale > 3)
	{
		map->plane->vect_x->scale--;
		map->plane->vect_y->scale--;
		map->plane->vect_z->scale--;
	}
	upd_vectors(map);
	create_image(map);
	draw_in_image(map, map->coord, im);
	mlx_put_image_to_window(map->connect, map->connect->win_list, im, 0, 0);
}
