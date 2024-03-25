/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:48:52 by peoriou           #+#    #+#             */
/*   Updated: 2024/03/23 10:57:46 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	add_image_to_front(t_image **image, t_image *new)
{
	new->next = *image;
	*image = new;
}

void	create_image(t_map *map)
{
	t_image	*new;
	int		wdth;
	int		hght;

	wdth = map->plane->width;
	hght = map->plane->height;
	new = (t_image *)malloc(sizeof(t_image));
	if (!new)
		free_close_exit(map, NULL, "Problem allocating memory.");
	new->img = mlx_new_image(map->connect, wdth, hght);
	if (!new->img)
		free_close_exit(map, NULL, "Problem creating mlx img.");
	add_image_to_front(&(map->image), new);
}
