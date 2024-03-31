/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:54:11 by poriou            #+#    #+#             */
/*   Updated: 2024/03/31 20:37:39 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_plane(t_plane *plane)
{
	if (plane->vect_x)
		free(plane->vect_x);
	if (plane->vect_y)
		free(plane->vect_y);
	if (plane->vect_z)
		free(plane->vect_z);
	if (plane->origin)
		free(plane->origin);
	free (plane);
}
