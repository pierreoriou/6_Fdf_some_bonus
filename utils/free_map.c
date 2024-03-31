/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:52:03 by peoriou           #+#    #+#             */
/*   Updated: 2024/03/31 20:06:48 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_map(t_map *map)
{
	if (map->grid)
		free(map->grid);
	if (map->coord)
		free_coord(&(map->coord));
	if (map->plane)
		free_plane(map->plane);
}
