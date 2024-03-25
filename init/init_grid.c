/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:04:32 by poriou            #+#    #+#             */
/*   Updated: 2024/03/23 11:14:50 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	*get_file_name(char *filename)
{
	int	len;
	int	i;

	i = 0;
	while (ft_isspace(filename[i]))
		i++;
	len = ft_strlen(filename);
	filename[len - 4] = '\0';
	while (len)
	{
		if (filename[len] == '/')
			return (filename + i + len + 1);
		len--;
	}
	return (filename + i);
}

t_grid	*init_grid(t_map *map, char *filename, int fd)
{
	t_grid	*grid;

	grid = (t_grid *)malloc(sizeof(t_grid));
	if (!grid)
		free_close_exit(map, NULL, "Problem allocating memory.\n");
	grid->name = get_file_name(filename);
	grid->fd = fd;
	grid->len = 0;
	grid->width = 0;
	grid->max_z = 0;
	grid->min_z = 0;
	return (grid);
}
