/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 13:52:03 by peoriou           #+#    #+#             */
/*   Updated: 2024/03/31 14:16:24 by poriou           ###   ########.fr       */
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
	if (plane->origin)
		free(plane->origin);
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
		free (cur->pixel);
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
	printf("CLEANUP : ...map coordinates freed...\n");
	if (map->plane)
		free_plane(map->plane);
	printf("CLEANUP : ...map plane freed...\n");
}
