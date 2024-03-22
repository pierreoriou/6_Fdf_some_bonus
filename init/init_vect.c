/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:08:45 by peoriou           #+#    #+#             */
/*   Updated: 2024/03/22 13:48:49 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_vect	*init_vect_x(t_map *map)
{
	t_vect	*vect_x;

	vect_x = (t_vect *)malloc(sizeof(t_vect));
	if (!vect_x)
		free_close_exit(map, NULL, "Problem allocating memory.");
	vect_x->x = map->plane->scale_x;
	vect_x->y = 0;
	vect_x->z = 0;
	return (vect_x);
}
