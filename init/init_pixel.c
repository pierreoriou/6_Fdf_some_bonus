/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:55:03 by poriou            #+#    #+#             */
/*   Updated: 2024/03/25 16:13:35 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_pixel *init_pixel(t_map *map)
{
	t_pixel	*new;

	new = (t_pixel *)malloc(sizeof(t_pixel));
	if (!new)
		free_close_exit(map, NULL, "Problem allocating memory.\n");
	new->x = 0;
	new->y = 0;
	return (new);
}
