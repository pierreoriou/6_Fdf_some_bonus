/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:42:59 by poriou            #+#    #+#             */
/*   Updated: 2024/03/31 15:11:34 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	init_map(t_map *map)
{
	map->grid = NULL;
	map->coord = NULL;
	map->plane = NULL;
	map->image = NULL;
	map->connect = mlx_init();
	if (map->connect == NULL)
		free_close_exit_before_init(map, "Problem initiationg mlx connect.\n");
}
