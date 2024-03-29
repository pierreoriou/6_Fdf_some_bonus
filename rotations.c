/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:38:23 by poriou            #+#    #+#             */
/*   Updated: 2024/03/29 15:44:15 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_up(t_map *map)
{
	map->plane->rotate_y += 10;
	upd_vectors(map);
	create_image(map);
	draw_in_image(map, map->coord, map->image->img);
	mlx_put_image_to_window(map->connect, map->connect->win_list, map->image->img, 0, 0);
}

void	rotate_down(t_map *map)
{
	map->plane->rotate_y -= 10;
	upd_vectors(map);
	create_image(map);
	draw_in_image(map, map->coord, map->image->img);
	mlx_put_image_to_window(map->connect, map->connect->win_list, map->image->img, 0, 0);
}
