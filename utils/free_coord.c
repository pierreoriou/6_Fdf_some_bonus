/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 18:52:23 by poriou            #+#    #+#             */
/*   Updated: 2024/03/31 20:37:33 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_coord(t_coord **coord)
{
	t_coord	*next;
	t_coord	*cur;

	if (!coord || !*coord)
		return ;
	cur = *coord;
	while (cur)
	{
		next = cur->next;
		free (cur->pixel);
		free (cur);
		cur = next;
	}
	*coord = NULL;
}

void	free_n_coord(t_coord **coord, int n_px)
{
	t_coord	*next;
	t_coord	*cur;

	if (!coord || !*coord)
		return ;
	cur = *coord;
	while (cur)
	{
		next = cur->next;
		if (n_px)
		{
			free (cur->pixel);
			n_px--;
		}
		free (cur);
		cur = next;
	}
	*coord = NULL;
}
