/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:51:28 by poriou            #+#    #+#             */
/*   Updated: 2024/03/31 18:52:02 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
