/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:23:19 by poriou            #+#    #+#             */
/*   Updated: 2024/03/22 16:38:49 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	check_content_format(char *content)
{
	int	i;

	i = 0;
	if ((content[i] == '+' || content[i] == '-') && ft_isdigit(content[i + 1]))
		i++;
	while (ft_isdigit(content[i]))
		i++;
	if (content[i] == '\0')
		return (1);
	if (ft_strncmp(content + i, ",0x", 3) == 0)
	{
		i += 3;
		if (ft_strlen(content + i) < 2 || ft_strlen(content + i) > 6)
			return (0);
		while (ft_ischarset(content[i], "123456789abcdefABCDEF"))
			i++;
		if (i != (int)ft_strlen(content))
			return (0);
	}
	else
		return (0);
	return (1);
}

static void	check_line_content(char **tab, char *str, t_map *map)
{
	int			i;
	int			val[3];
	static int	y = 0;

	i = 0;
	val[1] = y;
	while (tab[i])
	{
		if (!check_content_format(tab[i]))
		{
			ft_free_tab(tab);
			free_close_exit(map, str, "File: wrong data format.\n");
		}
		val[0] = i;
		val[2] = ft_atoi(tab[i]);
		init_coord(map, &(map->coord), val, tab[i]);
		i++;
	}
	y++;
}

static void	check_file_content(t_map *map)
{
	char	*str;
	char	**tab;

	while (1)
	{
		str = get_next_line(map->grid.fd);
		ft_printf(1, "%30? str = %s\n", "In check file content", str);
		if (!str)
			break ;
		tab = ft_split(str, " \n");
		if (!get_grid_len(tab, map))
		{
			ft_free_tab(tab);
			free_close_exit(map, str, "file: unequal nb of data / line.\n");
		}
		check_line_content(tab, str, map);
		map->grid.width++;
		free (str);
		ft_free_tab(tab);
	}
	free (str);
}

void	parse_grid(char *filename, t_map *map)
{
	char	*new_name;
	int		fd;

	new_name = check_file_name(filename, map);
	fd = open(new_name, __O_DIRECTORY);
	if (fd != -1)
		free_close_exit(map, new_name, "open: directory when file expected.\n");
	fd = open(new_name, O_RDONLY);
	if (fd == -1)
		free_close_exit(map, new_name, "open: file not found.\n");
	free (new_name);
	map->grid = init_grid(filename, fd);
	ft_printf(1, "%30? map->coord = %p\n", "In parse_coord", map->coord);
	check_file_content(map);
	ft_printf(1, "%30?\n", "File content checked...");
	print_coords(map->coord, "At the end of parse grid :");
	print_grid(&(map->grid), "At the end of parse grid :");
	close (fd);
}
