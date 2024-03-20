/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_coords.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:31:41 by poriou            #+#    #+#             */
/*   Updated: 2024/03/20 17:05:41 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	print_coords(t_coord *coord, char *msg)
{
	t_coord	*cur;
	int		i;

	cur = coord;
	i = 1;
	ft_printf(1, "%33?\n", msg);
	while (cur)
	{
		ft_printf(1, "coord %d %33? : %p\n", i, "ADDR", cur);
		ft_printf(1, "coord %d cur->x : %d\n", i, cur->x);
		ft_printf(1, "coord %d cur->y : %d\n", i, cur->y);
		ft_printf(1, "coord %d cur->z : %d\n", i, cur->z);
		if (cur->next)
			ft_printf(1, "coord %d ADDR NEXT : %p\n", i, cur->next);
		if (cur->prev)
			ft_printf(1, "coord %d ADDR PREV : %p\n", i, cur->prev);
		i++;
		cur = cur->next;
	}
}
