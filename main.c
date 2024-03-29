/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:21:32 by poriou            #+#    #+#             */
/*   Updated: 2024/03/29 17:10:54 by poriou           ###   ########.fr       */
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
	ft_printf(1, "%30? %s ...\n", "Map initiated :", argv[1]);
	parse_grid(argv[1], &map);
	ft_printf(1, "%30?\n", "Grid parsed and coordinates initiated...");
	create_plane(&map);
	ft_printf(1, "%30?\n", "Plane created...");
	// print_coords(map.coord, "In main after parse grid");
	create_image(&map);
	ft_printf(1, "%30?\n", "Image created...");
	draw_in_image(&map, map.coord, map.image->img);
	ft_printf(1, "%30?\n", "Image drawn...");
	// print_grid(map.grid, "In main");
	// print_plane(map.plane, "in main after draw in image");
	open_window(&map);
	ft_printf(1, "%30?\n", "Window opened...");
	cleanup(&map);
	ft_printf(1, "%32?\n", "Everything cleaned up, it seems like everything went smoothly.");
	return (0);
}
