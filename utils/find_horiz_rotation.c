/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_horiz_rotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:05:43 by poriou            #+#    #+#             */
/*   Updated: 2024/03/25 17:11:01 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	find_horiz_rotation(t_map *map)
{
	int	rotation;

	rotation = 15;
	if (map->grid->len >= 100 || map->grid->width >= 100)
		rotation += 10;
	if (map->grid->len >= 200 || map->grid->width >= 200)
		rotation += 10;
	if (map->grid->len >= 500 || map->grid->width >= 500)
		rotation += 10;
	return (rotation);
}
