/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_pixel_put.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:24:57 by poriou            #+#    #+#             */
/*   Updated: 2024/03/25 11:48:38 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_pixel_put(t_map *map, int x, int y, int color)
{
	char	*dst;
	int		offset;
	int		win_height;
	int		win_width;

	win_height = map->connect->win_list->height;
	win_width = map->connect->win_list->width;
	if (x < 0 || y < 0 || x > win_width || y > win_height)
		return ;
	offset = ((x * map->image->img->bpp) / 8) + y * size_line;
	dst = map->image->img->data + offset;
	*(int *)dst = color;
}
