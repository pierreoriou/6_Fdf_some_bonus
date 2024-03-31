/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:48:56 by poriou            #+#    #+#             */
/*   Updated: 2024/03/31 20:37:21 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	cleanup(t_map *map)
{
	if (map->image)
		free_images(map, &(map->image));
	mlx_destroy_window(map->connect, map->connect->win_list);
	mlx_destroy_display(map->connect);
	free_map(map);
	free (map->connect);
}
