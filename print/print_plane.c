/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 17:00:58 by poriou            #+#    #+#             */
/*   Updated: 2024/03/28 10:50:00 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	print_vect(t_vect *vect, char *msg)
{
	ft_printf(1, "%33?\n", msg);
	ft_printf(1, "vect->scale = %d\n", vect->scale);
	ft_printf(1, "vect->x = %d\n", vect->x_in_plane);
	ft_printf(1, "vect->y = %d\n", vect->y_in_plane);
}

void	print_plane(t_plane *plane, char *msg)
{
	ft_printf(1, "%33?\n", msg);
	ft_printf(1, "plane->width = %d\n", plane->width);
	ft_printf(1, "plane->height = %d\n", plane->height);
	ft_printf(1, "plane->margin_x = %d\n", plane->margin_x);
	ft_printf(1, "plane->margin_y = %d\n", plane->margin_y);
	ft_printf(1, "plane->rotate_z = %d\n", plane->rotate_z);
	ft_printf(1, "plane->rotate_y = %d\n", plane->rotate_y);
	if (plane->vect_x)
		print_vect(plane->vect_x, "Vector X:");
	if (plane->vect_y)
		print_vect(plane->vect_y, "Vector Y:");
	if (plane->vect_z)
		print_vect(plane->vect_z, "Vector Z:");
	if (plane->origin)
	{
		ft_printf(1, "plane->origin->x = %d\n", plane->origin->x);
		ft_printf(1, "plane->origin->y = %d\n", plane->origin->y);
	}
}
