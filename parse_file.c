/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 17:38:47 by poriou            #+#    #+#             */
/*   Updated: 2024/03/04 18:48:27 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	upd_grid_max(t_grid *grid, char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (ft_atoi(tab[i]) > grid->max_altitude)
			grid->max_altitude = ft_atoi(tab[i]);
		if (ft_atoi(tab[i]) < grid->max_depth)
			grid->max_depth = ft_atoi(tab[i]);
		i++;
	}
}

static void	upd_grid_width_and_max(t_grid *grid, int fd)
{
	char	**tab;
	char	*str;

	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		tab = ft_split(str, " \n");
		upd_grid_max(grid, tab);
		grid->grid_width++;
		free (str);
		ft_free_tab(tab);
	}
	free (str);
}

void	parse_file(char *filename)
{
	int		fd;
	t_grid	grid;
	char	*str;
	char	**tab;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		free_close_exit("", fd, "Error occured while opening file.\n");
	init_grid(&grid, filename);
	printf("-----\n");
	str = get_next_line(fd);
	tab = ft_split(str, " \n");
	grid.grid_len = get_tab_len(tab);
	grid.grid_width++;
	ft_free_tab(tab);
	upd_grid_width_and_max(&grid, fd);
	free (str);
	close (fd);
}
