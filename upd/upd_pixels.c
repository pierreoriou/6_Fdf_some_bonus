/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upd_pixels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:14:27 by poriou            #+#    #+#             */
/*   Updated: 2024/03/25 16:26:53 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	upd_pixels_new_scale(t_map *map)
{
	t_coord	*cur;

	cur = map->coord;
	while (cur)
	{
		cur->pixel->x = cur->x * map->plane->scale_x;
		cur->pixel->y = cur->y * map->plane->scale_y;
		cur = cur->next;
	}
}

// void	upd_pixels_new_z_rotation(t_map *map)
// {

// }
