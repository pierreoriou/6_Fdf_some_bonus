/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:24:57 by poriou            #+#    #+#             */
/*   Updated: 2024/03/28 14:36:33 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;
	int		offset;
	int		win_height;
	int		win_width;

	win_height = img->height;
	win_width = img->width;
	if (x < 0 || y < 0 || x > win_width || y > win_height)
		return ;
	offset = ((x * img->bpp) / 8) + y * img->size_line;
	dst = img->data + offset;
	*(int *)dst = color;
}
