/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:10:07 by poriou            #+#    #+#             */
/*   Updated: 2024/03/22 13:19:38 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	init_rotations_to_30(t_plane *plane)
{
	plane->rotate_y = 30;
	plane->rotate_z = 30;
}

void	init_scales_to_10(t_plane *plane)
{
	plane->scale_x = 10;
	plane->scale_y = 10;
	plane->scale_z = 10;
}

void	reduce_scales(t_plane **plane)
{
	(*plane)->scale_x--;
	(*plane)->scale_y--;
	(*plane)->scale_z--;
}

t_plane	*init_plane(t_map *map)
{
	t_plane	*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	if (!plane)
		free_close_exit(map, NULL, "Problem allocating memory.");
	plane->width = 0;
	plane->height = 0;
	plane->margin_x = 0;
	plane->margin_y = 0;
	plane->rotate_y = 0;
	return (plane);
}
