/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_close_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:54:23 by poriou            #+#    #+#             */
/*   Updated: 2024/03/25 10:34:22 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_close_exit(t_map *map, char *str, char *err_msg)
{
	free (str);
	ft_printf(1, "%31?\n", "EXITING : str freed...");
	if (map->grid)
	{
		close (map->grid->fd);
		ft_printf(1, "%31?\n", "EXITING : fd closed...");
	}
	free_map(map);
	ft_printf(1, "%31?\n", "EXITING : map freed...");
	ft_printf(2, "%31?", err_msg);
	exit (EXIT_FAILURE);
}

void	cleanup(t_map *map)
{
	if (map->image)
		free_images(map, &(map->image));
	ft_printf(1, "%30?\n", "CLEANUP : ...map images freed...");
	ft_printf(1, "in cleanup bef, map->connect = %p\n", map->connect);
	mlx_destroy_window(map->connect, map->connect->win_list);
	ft_printf(1, "%32?\n", "CLEANUP : window destroyed...");
	mlx_destroy_display(map->connect);
	ft_printf(1, "%32?\n", "CLEANUP : display destroyed...");
	free_map(map);
	ft_printf(1, "%32?\n", "CLEANUP : map freed...");
	free (map->connect);
}
