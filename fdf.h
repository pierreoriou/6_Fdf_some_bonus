/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:22:00 by poriou            #+#    #+#             */
/*   Updated: 2024/03/20 18:42:03 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "Libft/libft.h"
# include "Minilibx/mlx_int.h"
# include "Minilibx/mlx.h"
# include <math.h>
# include <X11/Xlib.h>

typedef struct s_grid
{
	char	*name;
	int		fd;
	int		len;
	int		width;
	int		max_z;
	int		min_z;
}			t_grid;

typedef struct s_pixel
{
	int	x;
	int	y;
}		t_pixel;


typedef struct s_coord
{
	int				x;
	int				y;
	int				z;
	struct s_coord	*head;
	struct s_coord	*prev;
	struct s_coord	*next;
	t_pixel			*pixel;
}					t_coord;

typedef struct s_plane
{
	int		scale_x;
	int		scale_y;
	int		scale_z;
	int		width;
	int		height;
	int		margin_x;
	int		margin_y;
	int		rotate_z;
	int		rotate_y;
	t_pixel	*origin;
}		t_plane;

typedef struct s_map
{
	t_grid	grid;
	t_coord	*coord;
	t_plane	*plane;
}			t_map;

int		main(int argc, char *argv[]);
void	parse_grid(char *arg, t_map *map);
void	create_plane(t_map *map);
void	open_window(t_xvar **connect, char *filename);

char	*check_file_name(char *filename, t_map *map);
// INIT
void	init_map(t_map *map);
t_grid	init_grid(char *filename, int fd);
t_coord	*init_coord(t_map *map, t_coord **coord, int *val);
// init plane
t_plane	*init_plane(t_map *map);
void	init_scales_to_10(t_plane *plane);
void	reduce_scales(t_plane **plane);
void	init_rotations_to_30(t_plane *plane);

// UTILS
void	free_close_exit(t_map *map, char *str, char *err_msg);
void	free_close(t_xvar *connect);
void	free_coord(t_coord **coord);
void	clean_and_exit(t_xvar **connect);
int		get_tab_len(char **tab, t_map *map);

// PRINT
void	print_grid(t_grid *grid, char *msg);
void	print_coords(t_coord *coord, char *msg);
void	print_plane(t_plane *plane, char *msg);

#endif
