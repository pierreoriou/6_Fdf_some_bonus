/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:22:00 by poriou            #+#    #+#             */
/*   Updated: 2024/03/19 16:59:36 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "Libft/libft.h"
# include "Minilibx/mlx_int.h"
# include "Minilibx/mlx.h"
# include <X11/Xlib.h>

typedef struct s_grid
{
	char	*name;
	int		fd;
	int		grid_len;
	int		grid_width;
	int		max_altitude;
	int		max_depth;
}			t_grid;

typedef struct s_map
{
	t_grid	grid;
}			t_map;

int		main(int argc, char *argv[]);
void	parse_grid(char *arg, t_map *map);
char	*check_file_name(char *filename, t_map *map);
void	open_window(t_xvar **connect, char *filename);
// INIT
t_map	*init_map(t_map **map);
t_grid	init_grid(char *filename, int fd);
// UTILS
void	free_close_exit(t_map *map, char *str, char *err_msg);
void	free_close(t_xvar *connect);
void	clean_and_exit(t_xvar **connect);
int		get_tab_len(char **tab);
// PRINT
void	print_grid(t_grid *grid);

#endif
