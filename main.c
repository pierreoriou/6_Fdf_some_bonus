/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:21:32 by poriou            #+#    #+#             */
/*   Updated: 2024/03/31 20:00:50 by poriou           ###   ########.fr       */
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
	parse_grid(argv[1], &map);
	create_plane(&map);
	create_image(&map);
	draw_in_image(&map, map.coord, map.image->img);
	open_window(&map);
	cleanup(&map);
	return (0);
}
