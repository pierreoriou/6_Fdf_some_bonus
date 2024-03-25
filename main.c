/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:21:32 by poriou            #+#    #+#             */
/*   Updated: 2024/03/24 11:58:36 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc != 2)
	{
		ft_printf(2, "Usage: %s <argument1>\n", argv[0]);
		exit (EXIT_FAILURE);
	}
	init_map(&map);
	ft_printf(1, "%30?\n", "Map initiated...");
	parse_grid(argv[1], &map);
	ft_printf(1, "%30?\n", "Grid parsed and coordinates initiated...");
	create_plane(&map);
	ft_printf(1, "%30?\n", "Plane created...");
	// create_image(&map);
	// ft_printf(1, "%30?\n", "Image created...");
	// mlx_put_image_to_window(map.connect, map.connect->win_list, map.image->img, 0, 0);
	// ft_printf(1, "%30?\n", "Image put in window...");
	// open_window(&map);
	// ft_printf(1, "%30?\n", "Window opened...");
	cleanup(&map);
	ft_printf(1, "%32?\n", "Everything cleaned up, it seems like everything went smoothly.");
	return (0);
}
