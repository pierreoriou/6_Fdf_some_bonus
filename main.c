/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:21:32 by poriou            #+#    #+#             */
/*   Updated: 2024/03/25 16:25:31 by poriou           ###   ########.fr       */
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
	print_coords(map.coord, "In main after parse grid");
	create_image(&map);
	ft_printf(1, "%30?\n", "Image created...");
	print_grid(map.grid, "In main");
	// put_plane_in_image(&map, map.image->img);
	// draw_in_image(&map, map.image->img);
	open_window(&map);
	ft_printf(1, "%30?\n", "Window opened...");
	cleanup(&map);
	ft_printf(1, "%32?\n", "Everything cleaned up, it seems like everything went smoothly.");
	return (0);
}
