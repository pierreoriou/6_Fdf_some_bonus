/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane_margin_x.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:12:50 by poriou            #+#    #+#             */
/*   Updated: 2024/03/25 17:20:41 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_plane_margin_x(t_map *map)
{
	int	margin_x;

	margin_x = 20;
	while ((map->plane->width + margin_x) > 1920)
		margin_x--;
	return (margin_x);
}
