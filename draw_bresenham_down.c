/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bresenham_down.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 14:26:39 by poriou            #+#    #+#             */
/*   Updated: 2024/03/31 15:32:16 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_bresenham_down_down(t_img *img, t_pixel cur, t_pixel prev, int c)
{
	int	dx;
	int	dy;
	int	p;

	dx = (int)fabs((double)(cur.x - prev.x));
	dy = (int)fabs((double)(cur.y - prev.y));
	p = (2 * dx) - dy;
	while (prev.y < cur.y)
	{
		my_pixel_put(img, prev.x, prev.y, c);
		prev.y++;
		if (p < 0)
			p += 2 * dx;
		else
		{
			p += 2 * dx - 2 * dy;
			prev.x++;
		}
	}
}

void	draw_bresenham_down_left(t_img *img, t_pixel cur, t_pixel prev, int c)
{
	int	dx;
	int	dy;
	int	p;

	dx = (int)fabs((double)(cur.x - prev.x));
	dy = (int)fabs((double)(cur.y - prev.y));
	p = (2 * dy) - dx;
	while (prev.x < cur.x)
	{
		my_pixel_put(img, prev.x, prev.y, c);
		prev.x++;
		if (p < 0)
			p += 2 * dy;
		else
		{
			p += 2 * dy - 2 * dx;
			prev.y++;
		}
	}
}
