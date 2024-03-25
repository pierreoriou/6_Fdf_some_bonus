/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upd_grid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:27:16 by peoriou           #+#    #+#             */
/*   Updated: 2024/03/23 11:17:56 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	upd_grid(t_map *map, int *val)
{
	static int	i = 0;

	if (i == 0)
	{
		map->grid->max_z = val[2];
		map->grid->min_z = val[2];
	}
	if (val[2] > map->grid->max_z)
		map->grid->max_z = val[2];
	if (val[2] < map->grid->min_z)
		map->grid->min_z = val[2];
	i++;
}
