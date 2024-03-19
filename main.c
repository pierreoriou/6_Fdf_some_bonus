/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:21:32 by poriou            #+#    #+#             */
/*   Updated: 2024/03/19 17:09:34 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	t_xvar	*connect;
	t_map	map;

	if (argc != 2)
	{
		ft_printf(2, "Usage: %s <argument1>\n", argv[0]);
		exit (EXIT_FAILURE);
	}
	// map = init_map(&map);
	ft_printf(1, "%30?\n", "Map initiated...");
	parse_grid(argv[1], &map);
	// printf("After init map in main, map.grid = %p, map = %p\n", map.grid, map);
	// parse_file(argv[1]);
	connect = NULL;
	open_window(&connect, argv[1]);
	ft_printf(1, "%30?\n", "Window opened...");
	ft_printf(1, "%32?\n", "Seems like everything went smoothly.");
	free_close(connect);
	return (0);
}
