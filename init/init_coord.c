/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 10:52:00 by poriou            #+#    #+#             */
/*   Updated: 2024/03/31 19:54:50 by poriou           ###   ########.fr       */
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

static void	init_coord_values(t_coord *new, int *val, char *elem)
{
	new->x = val[0];
	new->y = val[1];
	new->z = val[2];
	new->color = get_color(elem);
	new->prev_x = NULL;
	new->prev_y = NULL;
	new->prev = NULL;
	new->next = NULL;
}

int	init_coord(t_map *map, t_coord **coord, int *val, char *elem)
{
	t_coord		*new;
	static int	n_px = 0;

	new = (t_coord *)malloc(sizeof(t_coord));
	if (!new)
	{
		free_n_coord(coord, n_px);
		return (0);
	}
	init_coord_values(new, val, elem);
	coord_addback(coord, new);
	upd_grid(map, val);
	new->pixel = init_pixel();
	if (!new->pixel)
	{
		free_n_coord(coord, n_px);
		return (0);
	}
	n_px++;
	return (1);
}
