/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:10:07 by poriou            #+#    #+#             */
/*   Updated: 2024/03/28 10:43:56 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	init_scales_to_10(t_plane *plane)
{
	plane->vect_x->scale = 10;
	plane->vect_y->scale = 10;
	plane->vect_z->scale = 10;
}

void	reduce_scales(t_plane *plane)
{
	if (plane->vect_x->scale == 3|| plane->vect_y->scale == 3|| plane->vect_z->scale == 3)
		return ;
	plane->vect_x->scale--;
	plane->vect_y->scale--;
	plane->vect_z->scale--;
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
	plane->rotate_z = 0;
	return (plane);
}
