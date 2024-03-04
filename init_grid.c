/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:04:32 by poriou            #+#    #+#             */
/*   Updated: 2024/03/04 18:06:03 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	init_grid(t_grid *grid, char *filename)
{
	grid->name = filename;
	grid->grid_len = 0;
	grid->grid_width = 0;
	grid->max_altitude = 0;
	grid->max_depth = 0;
}
