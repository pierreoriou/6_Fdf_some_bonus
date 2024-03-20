/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 15:10:03 by poriou            #+#    #+#             */
/*   Updated: 2024/03/20 12:52:42 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	check_file_extension(char *trimmed_name, t_map *map)
{
	int	len;

	len = ft_strlen(trimmed_name);
	if (ft_strncmp(trimmed_name + (len - 4), ".fdf", 4) != 0)
		free_close_exit(map, trimmed_name, "Invalid file extension.\n");
}

static void	check_filename_len(char *filename, t_map *map)
{
	int		len;

	len = ft_strlen(filename);
	if (ft_strlen(filename) < 5)
		free_close_exit(map, filename, "Invalid file name format.\n");
	while (filename[len] != '/' && len)
		len--;
	if (len != 0)
	{
		if (ft_strlen(filename + len + 1) < 5)
			free_close_exit(map, filename, "Invalid file name format.\n");
	}
}

char	*check_file_name(char *filename, t_map *map)
{
	char	*trim_filename;

	trim_filename = ft_strtrim(filename, " \t\n\v\f\r");
	check_filename_len(trim_filename, map);
	check_file_extension(trim_filename, map);
	return (trim_filename);
}
