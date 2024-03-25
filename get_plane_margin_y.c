/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plane_margin_y.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:22:19 by poriou            #+#    #+#             */
/*   Updated: 2024/03/25 17:27:12 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_plane_margin_y(t_map *map)
{
	int	margin_y;

	margin_y = 5;
	if ((map->plane->height + margin_y) > 1050)
		margin_y = 0;
	return (margin_y);
}
