/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_close_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:54:23 by poriou            #+#    #+#             */
/*   Updated: 2024/03/31 20:05:19 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	abort_parsing(t_map *map, char **tab, char *str)
{
	ft_free_tab(tab);
	free (str);
	if (map->grid)
		free(map->grid);
	ft_putstr_fd("Error allocating memory during parsing.\n", 2);
	mlx_destroy_display(map->connect);
	free (map->connect);
	exit (EXIT_FAILURE);
}

void	free_close_exit(t_map *map, char *str, char *err_msg)
{
	if (str)
		free (str);
	if (map)
		free_map(map);
	ft_putstr_fd(err_msg, 2);
	mlx_destroy_display(map->connect);
	free (map->connect);
	exit (EXIT_FAILURE);
}

void	free_close_exit_before_init(t_map *map, char *err_msg)
{
	if (map)
		free_map(map);
	ft_putstr_fd(err_msg, 2);
	free (map->connect);
	exit (EXIT_FAILURE);
}
