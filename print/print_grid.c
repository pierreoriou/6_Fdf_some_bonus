/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:30:54 by poriou            #+#    #+#             */
/*   Updated: 2024/03/20 17:05:10 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	print_grid(t_grid *grid, char *msg)
{
	if (grid == NULL)
		return ;
	ft_printf(1, "%33?\n", msg);
	ft_printf(1, "grid->name : %s\n", grid->name);
	ft_printf(1, "grid->fd : %d\n", grid->fd);
	ft_printf(1, "grid->len : %d\n", grid->len);
	ft_printf(1, "grid->width : %d\n", grid->width);
	ft_printf(1, "grid->max_z : %d\n", grid->max_z);
	ft_printf(1, "grid->min_z : %d\n", grid->min_z);
}
