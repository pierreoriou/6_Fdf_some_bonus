/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:21:32 by poriou            #+#    #+#             */
/*   Updated: 2024/03/31 14:10:20 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./fdf <argument1>", 2);
		exit (EXIT_FAILURE);
	}
	init_map(&map);
	printf("Map initiated : %s ...\n", argv[1]);
	parse_grid(argv[1], &map);
	printf("Grid parsed and coordinates initiated...\n");
	create_plane(&map);
	printf("Plane created...\n");
	// print_coords(map.coord, "In main after parse grid");
	create_image(&map);
	printf("Image created...\n");
	draw_in_image(&map, map.coord, map.image->img);
	printf("Image drawn...\n");
	// print_grid(map.grid, "In main");
	// print_plane(map.plane, "in main after draw in image");
	open_window(&map);
	printf("Window opened...\n");
	cleanup(&map);
	printf("Everything cleaned up, it seems like everything went smoothly.\n");
	return (0);
}
