/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:00:58 by poriou            #+#    #+#             */
/*   Updated: 2024/03/20 17:11:16 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	print_plane(t_plane *plane, char *msg)
{
	ft_printf(1, "%33?\n", msg);
	ft_printf(1, "plane->scale_x = %d\n", plane->scale_x);
	ft_printf(1, "plane->scale_y = %d\n", plane->scale_y);
	ft_printf(1, "plane->scale_z = %d\n", plane->scale_z);
	ft_printf(1, "plane->width = %d\n", plane->width);
	ft_printf(1, "plane->height = %d\n", plane->height);
	ft_printf(1, "plane->margin_x = %d\n", plane->margin_x);
	ft_printf(1, "plane->margin_y = %d\n", plane->margin_y);
	ft_printf(1, "plane->rotate_z = %d\n", plane->rotate_z);
	ft_printf(1, "plane->rotate_y = %d\n", plane->rotate_y);
}