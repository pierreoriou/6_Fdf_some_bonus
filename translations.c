/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/29 15:07:51 by poriou            #+#    #+#             */
/*   Updated: 2024/03/31 20:32:38 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	translate_right(t_map *map)
{
	t_img	*im;
	int		max_right;

	im = map->image->img;
	max_right = map->plane->width + (map->plane->margin_x * 2);
	if (map->plane->origin->x < max_right)
		map->plane->origin->x += 10;
	else
		return ;
	create_image(map);
	draw_in_image(map, map->coord, im);
	mlx_put_image_to_window(map->connect, map->connect->win_list, im, 0, 0);
}

void	translate_left(t_map *map)
{
	t_img	*im;
	int		max_left;

	im = map->image->img;
	max_left = (map->plane->width + map->plane->margin_x) * (-1);
	if (map->plane->origin->x > max_left)
		map->plane->origin->x -= 10;
	else
		return ;
	create_image(map);
	draw_in_image(map, map->coord, im);
	mlx_put_image_to_window(map->connect, map->connect->win_list, im, 0, 0);
}

void	translate_up(t_map *map)
{
	t_img	*im;

	im = map->image->img;
	if (map->plane->origin->y > 0)
		map->plane->origin->y -= 10;
	else
		return ;
	create_image(map);
	draw_in_image(map, map->coord, im);
	mlx_put_image_to_window(map->connect, map->connect->win_list, im, 0, 0);
}

void	translate_down(t_map *map)
{
	t_img	*im;

	im = map->image->img;
	if (map->plane->origin->y < 2000)
		map->plane->origin->y += 10;
	else
		return ;
	create_image(map);
	draw_in_image(map, map->coord, im);
	mlx_put_image_to_window(map->connect, map->connect->win_list, im, 0, 0);
}
