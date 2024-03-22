/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_close_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:54:23 by poriou            #+#    #+#             */
/*   Updated: 2024/03/22 14:19:02 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
	free_map(map);
	ft_printf(1, "%31?\n", "EXITING : map freed...");
	ft_printf(2, "%31?", err_msg);
	exit (EXIT_FAILURE);
}

void	cleanup(t_map *map)
{
	if (map->grid.fd)
		close (map->grid.fd);
	ft_printf(1, "%32?\n", "CLEANUP : fd closed...");
	free_map(map);
	ft_printf(1, "%32?\n", "CLEANUP : map freed...");
}
