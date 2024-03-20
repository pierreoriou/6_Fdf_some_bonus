/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:52:00 by poriou            #+#    #+#             */
/*   Updated: 2024/03/20 16:04:02 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	coord_addback(t_coord **coord, t_coord *new)
{
	t_coord	*tmp;

	if (!*coord)
	{
		*coord = new;
		ft_printf(1, "%30? static new = %p\n", "In coord_addback", new);
		return ;
	}
	tmp = *coord;
	while (tmp->next)
	{
		tmp->next->prev = tmp;
		tmp = tmp->next;
	}
	new->prev = tmp;
	tmp->next = new;
	ft_printf(1, "%30? static tmp = %p\n", "In coord_addback", tmp);
	if (new->prev)
		ft_printf(1, "%30? static new->prev = %p\n", "In coord_addback", new->prev);
	ft_printf(1, "%30? static tmp->prev = %p\n", "In coord_addback", tmp->prev);
	ft_printf(1, "%30? static tmp->next = %p\n", "In coord_addback", tmp->next);
}

void	upd_grid(t_map *map, int *val)
{
	static int	i = 0;

	if (i == 0)
	{
		map->grid.max_z = val[2];
		map->grid.min_z = val[2];
	}
	if (val[2] > map->grid.max_z)
		map->grid.max_z = val[2];
	if (val[2] < map->grid.min_z)
		map->grid.min_z = val[2];
	i++;
}

// ft_printf(1, "%30? static new = %p\n", "In init coord", new);
t_coord	*init_coord(t_map *map, t_coord **coord, int *val)
{
	t_coord	*new;

	new = (t_coord *)malloc(sizeof(t_coord));
	if (!new)
		free_close_exit(map, NULL, "Problem allocating memory.");
	new->x = val[0];
	new->y = val[1];
	new->z = val[2];
	new->prev = NULL;
	new->next = NULL;
	coord_addback(coord, new);
	upd_grid(map, val);
	return (new);
}
