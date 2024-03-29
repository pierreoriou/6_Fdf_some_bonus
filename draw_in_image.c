/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_in_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:23:56 by poriou            #+#    #+#             */
/*   Updated: 2024/03/29 15:45:10 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_coord_prev_x(t_pixel *cur, t_pixel *prev, t_img *img, int col)
{
	int		dx;
	int		dy;
	float	m;

	dx = cur->x - prev->x;
	dy = cur->y - prev->y;
	if (dx == 0)
		m = (float)dy;
	else
		m = (float)dy / (float)dx;
	if (m <= -1)
		draw_bresenham_up_up(img, *cur, *prev, col);
	else if (m <= 0)
		draw_bresenham_up_left(img, *cur, *prev, col);
	else if (m <= 1)
		draw_bresenham_down_left(img, *cur, *prev, col);
	else
		draw_bresenham_down_down(img, *cur, *prev, col);
}

static void	draw_coord_prev_y(t_pixel *cur, t_pixel *prev, t_img *img, int col)
{
	int		dx;
	int		dy;
	float	m;

	dx = cur->x - prev->x;
	dy = cur->y - prev->y;
	if (dx == 0)
		m = (float)dy;
	else
		m = (float)dy / (float)dx;
	if (m <= -1)
		draw_bresenham_up_up(img, *cur, *prev, col);
	else if (m <= 0)
		draw_bresenham_up_left(img, *cur, *prev, col);
	else if (m <= 1)
		draw_bresenham_down_left(img, *cur, *prev, col);
	else
		draw_bresenham_down_down(img, *cur, *prev, col);
}

void	draw_in_image(t_map *map, t_coord *coord, t_img *img)
{
	t_pixel *prev_x;
	t_pixel *prev_y;
	t_pixel *cur;
	int		color;

	upd_coord(map->plane, coord);
	if (coord->next == NULL)
		my_pixel_put(img, 70, 50, 0xFFFFFF);
	while (coord)
	{
		cur = coord->pixel;
		if (coord->prev_x)
		{
			prev_x = coord->prev_x->pixel;
			color = coord->prev_x->color;
			draw_coord_prev_x(cur, prev_x, img, color);
		}
		if (coord->prev_y)
		{
			prev_y = coord->prev_y->pixel;
			color = coord->prev_y->color;
			draw_coord_prev_y(cur, prev_y, img, color);
		}
		coord = coord->next;
	}
}
