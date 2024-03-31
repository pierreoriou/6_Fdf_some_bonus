/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:07:51 by poriou            #+#    #+#             */
/*   Updated: 2024/03/31 15:38:13 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_right(t_map *map)
{
	t_img	*im;

	im = map->image->img;
	map->plane->origin->x += 10;
	create_image(map);
	draw_in_image(map, map->coord, im);
	mlx_put_image_to_window(map->connect, map->connect->win_list, im, 0, 0);
}

void	translate_left(t_map *map)
{
	t_img	*im;

	im = map->image->img;
	map->plane->origin->x -= 10;
	create_image(map);
	draw_in_image(map, map->coord, im);
	mlx_put_image_to_window(map->connect, map->connect->win_list, im, 0, 0);
}

void	translate_up(t_map *map)
{
	t_img	*im;

	im = map->image->img;
	map->plane->origin->y -= 10;
	create_image(map);
	draw_in_image(map, map->coord, im);
	mlx_put_image_to_window(map->connect, map->connect->win_list, im, 0, 0);
}

void	translate_down(t_map *map)
{
	t_img	*im;

	im = map->image->img;
	map->plane->origin->y += 10;
	create_image(map);
	draw_in_image(map, map->coord, im);
	mlx_put_image_to_window(map->connect, map->connect->win_list, im, 0, 0);
}
