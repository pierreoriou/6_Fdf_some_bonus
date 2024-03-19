/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_grid.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:23:19 by poriou            #+#    #+#             */
/*   Updated: 2024/03/19 17:21:47 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// static int	check_content_format(char *content)
// {
// 	int	i;

// 	i = 0;
// 	if ((content[i] == '+' || content[i] == '-') && ft_isdigit(content[i + 1]))
// 		i++;
// 	while (ft_isdigit(content[i]))
// 		i++;
// 	if (content[i] == '\0')
// 		return (1);
// 	if (ft_strncmp(content + i, ",0x", 3) == 0)
// 	{
// 		i += 3;
// 		if (ft_strlen(content + i) < 2 || ft_strlen(content + i) > 6)
// 		{
// 			return (0);
// 		}
// 		while (ft_ischarset(content[i], "123456789abcdefABCDEF"))
// 			i++;
// 		if (i != (int)ft_strlen(content))
// 			return (0);
// 	}
// 	else
// 		return (0);
// 	return (1);
// }

// static int	check_line_content(char **tab, char *str, t_map *map, int elems)
// {
// 	int	i;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		if (!check_content_format(tab[i]))
// 		{
// 			ft_free_tab(tab);
// 			free_close_exit(map, str, "File contains wrong data format.\n");
// 		}
// 		i++;
// 	}
// 	if (i != elems)
// 	{
// 		ft_free_tab(tab);
// 		free_close_exit(map, str, "File contains unequal data per line.\n");
// 	}
// 	return (i);
// }

// static void	check_file_content(t_map *map)
// {
// 	char	*str;
// 	char	**tab;
// 	int		elems;

// 	tab = NULL;
// 	str = get_next_line(map->grid->fd);
// 	if (!str)
// 		free_close_exit(map, str, "No content in file.\n");
// 	tab = ft_split(str, " \n");
// 	free (str);
// 	elems = get_tab_len(tab);
// 	check_line_content(tab, str, map, elems);
// 	ft_free_tab(tab);
// 	while (str != NULL)
// 	{
// 		str = get_next_line(map->grid->fd);
// 		if (!str)
// 			break ;
// 		tab = ft_split(str, " \n");
// 		check_line_content(tab, str, map, elems);
// 		free (str);
// 		ft_free_tab(tab);
// 	}
// 	free (str);
// }

void	parse_grid(char *filename, t_map *map)
{
	char	*new_name;
	int		fd;

	new_name = check_file_name(filename, map);
	ft_printf(1, "%30?\n", "File name checked...");
	fd = open(new_name, O_RDONLY);
	if (fd == -1)
		free_close_exit(map, new_name, "open: no such file.\n");
	free (new_name);
	map->grid = init_grid(filename, fd);
	printf("In parse grid, after init grid map->grid = %p\n", &(map->grid));
	print_grid(&(map->grid));
	// check_file_content(map);
	close (fd);
}
