/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_grid.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 18:04:32 by poriou            #+#    #+#             */
/*   Updated: 2024/03/20 15:50:04 by poriou           ###   ########.fr       */
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

t_grid	init_grid(char *filename, int fd)
{
	t_grid	grid;

	grid.name = get_file_name(filename);
	grid.fd = fd;
	grid.len = 0;
	grid.width = 0;
	grid.max_z = 0;
	grid.min_z = 0;
	return (grid);
}
