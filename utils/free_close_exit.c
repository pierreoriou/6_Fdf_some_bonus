/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_close_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:54:23 by poriou            #+#    #+#             */
/*   Updated: 2024/03/31 15:11:52 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_close_exit(t_map *map, char *str, char *err_msg)
{
	if (str)
		free (str);
	printf("EXITING : str freed...\n");
	if (map)
		free_map(map);
	printf("EXITING : map freed...\n");
	ft_putstr_fd(err_msg, 2);
	mlx_destroy_display(map->connect);
	free (map->connect);
	exit (EXIT_FAILURE);
}

void	free_close_exit_before_init(t_map *map, char *err_msg)
{
	if (map)
		free_map(map);
	printf("EXITING : map freed...\n");
	ft_putstr_fd(err_msg, 2);
	free (map->connect);
	exit (EXIT_FAILURE);
}

void	cleanup(t_map *map)
{
	if (map->image)
		free_images(map, &(map->image));
	printf("CLEANUP : ...map images freed...\n");
	mlx_destroy_window(map->connect, map->connect->win_list);
	printf("CLEANUP : window destroyed...\n");
	mlx_destroy_display(map->connect);
	printf("CLEANUP : display destroyed...\n");
	free_map(map);
	printf("CLEANUP : map freed...\n");
	free (map->connect);
}
