/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_optimal_vert_rotation.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:49:35 by poriou            #+#    #+#             */
/*   Updated: 2024/03/25 13:44:52 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	find_optimal_vert_rotation(t_map *map)
{
	int		vert_rotation;
	float	tot_len;
	float	len_x;
	float	len_y;

	vert_rotation = 0;
	len_x = (map->grid->len - 1) * map->plane->scale_x;
	len_y = (map->grid->width - 1) * map->plane->scale_y;
	while (vert_rotation <= 90)
	{
		len_x = len_x * sin(vert_rotation * M_PI / 180);
		len_y = len_y * cos(vert_rotation * M_PI / 180);
		if (tot_len > len_x + len_y)
			return (vert_rotation - 1);
		tot_len = len_x + len_y;
		len_x = (map->grid->len - 1) * map->plane->scale_x;
		len_y = (map->grid->width - 1) * map->plane->scale_y;
		vert_rotation++;
	}
	return (vert_rotation);
}
