/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_close_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:54:23 by poriou            #+#    #+#             */
/*   Updated: 2024/03/20 16:53:31 by poriou           ###   ########.fr       */
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
		free (cur);
		cur = next;
	}
	*coord = NULL;
}

void	free_close(t_xvar *connect)
{
	mlx_destroy_window(connect, connect->win_list);
	mlx_destroy_display(connect);
	free (connect);
}

void	free_close_exit(t_map *map, char *str, char *err_msg)
{
	free (str);
	ft_printf(1, "%31?\n", "EXITING : str freed...");
	if (map->grid.fd)
		close (map->grid.fd);
	ft_printf(1, "%31?\n", "EXITING : fd closed...");
	free_coord(&(map->coord));
	ft_printf(1, "%31?\n", "EXITING : map coord freed...");
	free(map->plane);
	ft_printf(1, "%31?\n", "EXITING : map plane freed...");
	ft_printf(2, "%31?", err_msg);
	exit (EXIT_FAILURE);
}
