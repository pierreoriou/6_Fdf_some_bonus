/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:08:45 by peoriou           #+#    #+#             */
/*   Updated: 2024/03/31 19:11:19 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_vect	*init_vect_x(t_map *map)
{
	t_vect	*vect_x;

	vect_x = (t_vect *)malloc(sizeof(t_vect));
	if (!vect_x)
	{
		free(map->grid);
		free_coord(&(map->coord));
		free(map->plane);
		ft_putstr_fd("Problem allocating memory.\n", 2);
		exit (EXIT_FAILURE);
	}
	vect_x->scale = 100;
	vect_x->x_in_plane = 0;
	vect_x->y_in_plane = 0;
	return (vect_x);
}

t_vect	*init_vect_y(t_map *map)
{
	t_vect	*vect_y;

	vect_y = (t_vect *)malloc(sizeof(t_vect));
	if (!vect_y)
	{
		free(map->grid);
		free_coord(&(map->coord));
		free(map->plane->vect_x);
		free(map->plane);
		ft_putstr_fd("Problem allocating memory.\n", 2);
		exit (EXIT_FAILURE);
	}
	vect_y->scale = 100;
	vect_y->x_in_plane = vect_y->scale;
	vect_y->y_in_plane = 0;
	return (vect_y);
}

t_vect	*init_vect_z(t_map *map)
{
	t_vect	*vect_z;

	vect_z = (t_vect *)malloc(sizeof(t_vect));
	if (!vect_z)
	{
		free(map->grid);
		free_coord(&(map->coord));
		free(map->plane->vect_x);
		free(map->plane->vect_y);
		free(map->plane);
		ft_putstr_fd("Problem allocating memory.\n", 2);
		exit (EXIT_FAILURE);
	}
	vect_z->scale = 100;
	vect_z->x_in_plane = 0;
	vect_z->y_in_plane = vect_z->scale;
	return (vect_z);
}
