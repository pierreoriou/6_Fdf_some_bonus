/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:52:00 by poriou            #+#    #+#             */
/*   Updated: 2024/03/22 16:38:43 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static t_coord	*get_prev_y(t_coord *new, t_coord *last)
{
	while (last)
	{
		if (last->y < new->y && new->x == last->x)
			return (last);
		last = last->prev;
	}
	return (NULL);
}

static void	coord_addback(t_coord **coord, t_coord *new)
{
	if (!*coord)
	{
		*coord = new;
		ft_printf(1, "%30?\n", "first coord");
		(*coord)->head = new;
		return ;
	}
	(*coord)->head->next = new;
	new->prev = (*coord)->head;
	if (new->x != 0)
		new->prev_x = (*coord)->head;
	else
		new->prev_x = NULL;
	if (new->y != 0)
		new->prev_y = get_prev_y(new, (*coord)->head);
	(*coord)->head = new;
}

// ft_printf(1, "%30? static new = %p\n", "In init coord", new);
t_coord	*init_coord(t_map *map, t_coord **coord, int *val, char *elem)
{
	t_coord	*new;

	new = (t_coord *)malloc(sizeof(t_coord));
	if (!new)
		free_close_exit(map, NULL, "Problem allocating memory.");
	new->x = val[0];
	new->y = val[1];
	new->z = val[2];
	new->color = get_color(elem);
	new->prev_x = NULL;
	new->prev_y = NULL;
	new->prev = NULL;
	new->next = NULL;
	coord_addback(coord, new);
	upd_grid(map, val);
	return (new);
}
