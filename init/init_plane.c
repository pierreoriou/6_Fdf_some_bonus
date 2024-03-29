/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:10:07 by poriou            #+#    #+#             */
/*   Updated: 2024/03/29 11:46:27 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
