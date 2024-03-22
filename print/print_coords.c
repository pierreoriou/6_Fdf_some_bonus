/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_coords.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:31:41 by poriou            #+#    #+#             */
/*   Updated: 2024/03/22 16:48:17 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	print_coords(t_coord *coord, char *msg)
{
	t_coord	*cur;
	int		i;

	cur = coord;
	i = 1;
	ft_printf(1, "---%33?---\n", msg);
	if (cur->head)
		ft_printf(1, "coord %d >>>>> HEAD <<<<< : %p\n", i, cur->head);
	while (cur)
	{
		if (cur->prev && cur->y != cur->prev->y)
			ft_printf(1, "%30?\n", "------------------------");
		ft_printf(1, "coord %d %33? : %p\n", i, "ADDR", cur);
		ft_printf(1, "coord %d cur->x : %d\n", i, cur->x);
		ft_printf(1, "coord %d cur->y : %d\n", i, cur->y);
		ft_printf(1, "coord %d cur->z : %d\n", i, cur->z);
		ft_printf(1, "coord %d cur->color : %d\n", i, cur->color);
		if (cur->next)
			ft_printf(1, "coord %d ADDR NEXT : %p\n", i, cur->next);
		ft_printf(1, "coord %d ADDR PREV_X : %p\n", i, cur->prev_x);
		ft_printf(1, "coord %d ADDR PREV_Y : %p\n", i, cur->prev_y);
		i++;
		cur = cur->next;
	}
}