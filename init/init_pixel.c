/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:55:03 by poriou            #+#    #+#             */
/*   Updated: 2024/03/31 20:41:16 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_pixel	*init_pixel_origin(t_map *map)
{
	t_pixel	*new;

	new = (t_pixel *)malloc(sizeof(t_pixel));
	if (!new)
	{
		free(map->grid);
		free_coord(&(map->coord));
		free(map->plane->vect_x);
		free(map->plane->vect_y);
		free(map->plane->vect_z);
		free(map->plane);
		ft_putstr_fd("Problem allocating memory.\n", 2);
		exit (EXIT_FAILURE);
	}
	new->x = 0;
	new->y = 0;
	return (new);
}

t_pixel	*init_pixel(void)
{
	t_pixel	*new;

	new = (t_pixel *)malloc(sizeof(t_pixel));
	if (!new)
		return (NULL);
	new->x = 0;
	new->y = 0;
	return (new);
}
