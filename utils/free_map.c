/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:52:03 by peoriou           #+#    #+#             */
/*   Updated: 2024/03/24 11:53:24 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_plane(t_plane *plane)
{
	if (plane->vect_x)
		free(plane->vect_x);
	if (plane->vect_y)
		free(plane->vect_y);
	if (plane->vect_z)
		free(plane->vect_z);
	free (plane);
}

void	free_coord(t_coord **coord)
{
	t_coord	*next;
	t_coord	*cur;

	if (!coord || !*coord)
		return ;
	cur = *coord;
	while (cur)
	{
		next = cur->next;
		free (cur);
		cur = next;
	}
	*coord = NULL;
}

void	free_images(t_map *map, t_image **image)
{
	t_image	*next;
	t_image	*tmp;

	tmp = *image;
	while (tmp)
	{
		next = tmp->next;
		mlx_destroy_image(map->connect, tmp->img);
		free(tmp);
		tmp = next;
	}
	*image = NULL;
}

void	free_map(t_map *map)
{
	if (map->grid)
		free(map->grid);
	if (map->coord)
		free_coord(&(map->coord));
	ft_printf(1, "%30?\n", "...map coordinates freed...");
	if (map->plane)
		free_plane(map->plane);
	ft_printf(1, "%30?\n", "...map plane freed...");
	if (map->image)
		free_images(map, &(map->image));
	ft_printf(1, "%30?\n", "...map images freed...");
}
