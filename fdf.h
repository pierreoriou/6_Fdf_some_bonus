/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:22:00 by poriou            #+#    #+#             */
/*   Updated: 2024/03/23 11:16:24 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "Libft/libft.h"
# include <math.h>
# include "Minilibx/mlx_int.h"
# include "Minilibx/mlx.h"
# include <X11/Xlib.h>

typedef struct s_image
{
	t_img			*img;
	struct s_image	*next;
}					t_image;

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
	int				color;
	struct s_coord	*prev_x;
	struct s_coord	*prev_y;
	struct s_coord	*head;
	struct s_coord	*prev;
	struct s_coord	*next;
	t_pixel			*pixel;
}					t_coord;

typedef struct s_vect
{
	int	x;
	int	y;
	int	z;
	int	x_in_plane;
	int	y_in_plane;
	int	x_angle;
	int	y_angle;
	int	z_angle;
	int	vertic_angle;
	int	horiz_angle;
}		t_vect;

typedef struct s_plane
{
	int		scale_x;
	int		scale_y;
	int		scale_z;
	int 	initial_angle_x;
	int 	initial_angle_y;
	int 	initial_angle_z;
	int		width;
	int		height;
	int		margin_x;
	int		margin_y;
	int		rotate_z;
	int		rotate_y;
	t_vect	*vect_x;
	t_vect	*vect_y;
	t_vect	*vect_z;
	t_pixel	*origin;
}			t_plane;

typedef struct s_map
{
	t_xvar	*connect;
	t_grid	*grid;
	t_coord	*coord;
	t_plane	*plane;
	t_image	*image;
}			t_map;

int		main(int argc, char *argv[]);
void	parse_grid(char *arg, t_map *map);
char	*check_file_name(char *filename, t_map *map);
void	create_plane(t_map *map);
void	create_image(t_map *map);
int		get_plane_width(t_map *map);
int		get_plane_height(t_map *map);
void	open_window(t_map *map);

// INIT
void	init_map(t_map *map);
t_grid	*init_grid(t_map *map, char *filename, int fd);
t_coord	*init_coord(t_map *map, t_coord **coord, int *val, char *elem);
t_plane	*init_plane(t_map *map);
t_vect	*init_vect_x(t_map *map);
t_vect	*init_vect_y(t_map *map);
t_vect	*init_vect_z(t_map *map);
void	init_scales_to_10(t_plane *plane);
void	reduce_scales(t_plane **plane);
void	init_rotations_to_30(t_plane *plane);

// UPD
void	upd_grid(t_map *map, int *val);

// UTILS
void	free_close_exit(t_map *map, char *str, char *err_msg);
void	free_close(t_xvar *connect);
void	free_coord(t_coord **coord);
void	free_map(t_map *map);
void	clean_and_exit(t_xvar **connect);
int		get_grid_len(char **tab, t_map *map);
int		get_color(char *elem);
void	cleanup(t_map *map);

// PRINT
void	print_grid(t_grid *grid, char *msg);
void	print_coords(t_coord *coord, char *msg);
void	print_plane(t_plane *plane, char *msg);

#endif
