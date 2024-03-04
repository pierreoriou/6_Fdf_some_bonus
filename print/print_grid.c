/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:30:54 by poriou            #+#    #+#             */
/*   Updated: 2024/03/04 18:33:17 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	print_grid(t_grid *grid)
{
	ft_printf(1, "grid->name : %s\n", grid->name);
	ft_printf(1, "grid->grid_len : %d\n", grid->grid_len);
	ft_printf(1, "grid->grid_width : %d\n", grid->grid_width);
	ft_printf(1, "grid->max_altitude : %d\n", grid->max_altitude);
	ft_printf(1, "grid->max_depth : %d\n", grid->max_depth);
}
