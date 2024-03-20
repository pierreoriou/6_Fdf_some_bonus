/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:21:32 by poriou            #+#    #+#             */
/*   Updated: 2024/03/20 18:49:40 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_map	map;
	// t_xvar	*connect;

	if (argc != 2)
	{
		ft_printf(2, "Usage: %s <argument1>\n", argv[0]);
		exit (EXIT_FAILURE);
	}
	init_map(&map);
	ft_printf(1, "%30? map.coord = %p\n", "In main,", map.coord);
	ft_printf(1, "%30?\n", "Map initiated...");
	parse_grid(argv[1], &map);
	create_plane(&map);
	// printf("After init map in main, map.grid = %p, map = %p\n", map.grid, map);
	// parse_file(argv[1]);
	//connect = NULL;
	//open_window(&connect, argv[1]);
	// ft_printf(1, "%30?\n", "Window opened...");
	free_coord(&(map.coord));
	ft_printf(1, "%32?\n", "coord freed...");
	free(map.plane);
	ft_printf(1, "%32?\n", "plane freed...");
	//free_close(connect, map);
	ft_printf(1, "%32?\n", "Seems like everything went smoothly.");
	return (0);
}
