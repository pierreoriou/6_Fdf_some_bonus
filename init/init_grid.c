/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:04:32 by poriou            #+#    #+#             */
/*   Updated: 2024/03/19 17:25:41 by poriou           ###   ########.fr       */
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
		ft_printf(1, "%31?[%d] %c\n", "In get file name, filename =", len, filename[len]);
		if (filename[len] == '/')
			return (filename + i + len + 1);
		len--;
	}
	return (filename + i);
}

t_grid	init_grid(char *filename, int fd)
{
	t_grid	grid;

	ft_printf(1, "%31? %s\n", "In init grid, filename =", filename);
	grid.name = get_file_name(filename);
	grid.fd = fd;
	grid.grid_len = 0;
	grid.grid_width = 0;
	grid.max_altitude = 0;
	grid.max_depth = 0;
	return (grid);
}
