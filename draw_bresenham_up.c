/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bresenham_up.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:26:39 by poriou            #+#    #+#             */
/*   Updated: 2024/03/28 17:25:38 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_bresenham_up_up(t_img *img, t_pixel cur, t_pixel prev, int color)
{
	int	dx;
	int	dy;
	int	p;

	dx = llabs(cur.x - prev.x);
	dy = llabs(cur.y - prev.y);
	p = (2 * dx) - dy;
	while (prev.y > cur.y)
	{
		my_pixel_put(img, prev.x, prev.y, color);
		prev.y--;
		if (p < 0)
			p += 2 * dx;
		else
		{
			p += 2 * dx - 2 * dy;
			prev.x++;
		}
	}
}

void	draw_bresenham_up_left(t_img *img, t_pixel cur, t_pixel prev, int color)
{
	int	dx;
	int	dy;
	int	p;

	dx = llabs(cur.x - prev.x);
	dy = llabs(cur.y - prev.y);
	p = (2 * dy) - dx;
	while (prev.x < cur.x)
	{
		my_pixel_put(img, prev.x, prev.y, color);
		prev.x++;
		if (p < 0)
			p += 2 * dy;
		else
		{
			p += 2 * dy - 2 * dx;
			prev.y--;
		}
	}
}
