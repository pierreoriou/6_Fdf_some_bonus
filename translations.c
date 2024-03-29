/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:07:51 by poriou            #+#    #+#             */
/*   Updated: 2024/03/29 15:28:39 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_right(t_map *map)
{
	map->plane->origin->x += 10;
	create_image(map);
	draw_in_image(map, map->coord, map->image->img);
	mlx_put_image_to_window(map->connect, map->connect->win_list, map->image->img, 0, 0);
}

void	translate_left(t_map *map)
{
	map->plane->origin->x -= 10;
	create_image(map);
	draw_in_image(map, map->coord, map->image->img);
	mlx_put_image_to_window(map->connect, map->connect->win_list, map->image->img, 0, 0);
}

void	translate_up(t_map *map)
{
	map->plane->origin->y -= 10;
	create_image(map);
	draw_in_image(map, map->coord, map->image->img);
	mlx_put_image_to_window(map->connect, map->connect->win_list, map->image->img, 0, 0);
}

void	translate_down(t_map *map)
{
	map->plane->origin->y += 10;
	create_image(map);
	draw_in_image(map, map->coord, map->image->img);
	mlx_put_image_to_window(map->connect, map->connect->win_list, map->image->img, 0, 0);
}
