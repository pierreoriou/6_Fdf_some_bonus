/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane_origin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:28:17 by poriou            #+#    #+#             */
/*   Updated: 2024/03/25 17:30:33 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_pixel	*init_plane_origin(t_map *map)
{
	t_pixel	*origin;

	origin = init_pixel(map);
	origin->x =
	origin->y =
	return (origin);
}
