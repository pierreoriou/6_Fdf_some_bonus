/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 10:48:52 by peoriou           #+#    #+#             */
/*   Updated: 2024/03/29 15:26:14 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	add_image_to_front(t_map *map, t_image *new)
{
	t_image *tmp;

	tmp = map->image;
	new->next = tmp;
	map->image = new;
}

void	create_image(t_map *map)
{
	t_image	*new;
	int		wdth;
	int		hght;

	wdth = map->plane->width + (map->plane->margin_x * 2);
	hght = map->plane->height + (map->plane->margin_y * 2);
	new = (t_image *)malloc(sizeof(t_image));
	if (!new)
		free_close_exit(map, NULL, "Problem allocating memory.");
	new->next = NULL;
	new->img = mlx_new_image(map->connect, wdth, hght);
	if (!new->img)
		free_close_exit(map, NULL, "Problem creating mlx img.");
	add_image_to_front(map, new);
}
