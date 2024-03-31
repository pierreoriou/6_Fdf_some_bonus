/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:22:00 by poriou            #+#    #+#             */
/*   Updated: 2024/03/31 20:34:02 by poriou           ###   ########.fr       */
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
	int	scale;
	int	x_in_plane;
	int	y_in_plane;
}		t_vect;

typedef struct s_plane
{
	t_vect	*vect_x;
	t_vect	*vect_y;
	t_vect	*vect_z;
	int		rotate_z;
	int		rotate_y;
	int		width;
	int		height;
	int		margin_x;
	int		margin_y;
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
void	draw_in_image(t_map *map, t_coord *coord, t_img *img);
void	create_image(t_map *map);
int		get_plane_margin_x(t_map *map);
int		get_plane_margin_y(t_map *map);
int		get_plane_width(t_map *map);
int		get_plane_height(t_map *map);
void	my_pixel_put(t_img *img, int x, int y, int color);
void	draw_bresenham_up_up(t_img *img, t_pixel cur, t_pixel prev, int c);
void	draw_bresenham_up_left(t_img *img, t_pixel cur, t_pixel prev, int c);
void	draw_bresenham_down_down(t_img *img, t_pixel cur, t_pixel prev, int c);
void	draw_bresenham_down_left(t_img *img, t_pixel cur, t_pixel prev, int c);
void	open_window(t_map *map);
void	translate_right(t_map *map);
void	translate_left(t_map *map);
void	translate_up(t_map *map);
void	translate_down(t_map *map);
void	zoom_in(t_map *map);
void	zoom_out(t_map *map);
void	rotate_up(t_map *map);
void	rotate_down(t_map *map);

// INIT
void	init_map(t_map *map);
t_grid	*init_grid(t_map *map, char *filename, int fd);
int		init_coord(t_map *map, t_coord **coord, int *val, char *elem);
t_pixel	*init_pixel(void);
t_pixel	*init_pixel_origin(t_map *map);
t_plane	*init_plane(t_map *map);
t_vect	*init_vect_x(t_map *map);
t_vect	*init_vect_y(t_map *map);
t_vect	*init_vect_z(t_map *map);
void	init_scales_to_10(t_plane *plane);
t_pixel	*init_plane_origin(t_map *map);

// UPD
void	upd_grid(t_map *map, int *val);
void	upd_pixels_new_scale(t_map *map);
int		upd_plane_width(t_map *map);
void	upd_vectors(t_map *map);
void	upd_coord(t_plane *plane, t_coord *coord);

// UTILS
void	abort_parsing(t_map *map, char **tab, char *str);
void	free_close_exit(t_map *map, char *str, char *err_msg);
void	free_close_exit_before_init(t_map *map, char *err_msg);
void	reduce_scales(t_plane *plane);
void	free_map(t_map *map);
void	free_images(t_map *map, t_image **image);
void	free_coord(t_coord **coord);
void	free_n_coord(t_coord **coord, int n_px);
void	free_plane(t_plane *plane);
int		find_optimal_vert_rotation(t_map *map);
int		find_horiz_rotation(t_map *map);
void	cleanup(t_map *map);
int		get_color(char *elem);
int		get_grid_len(char **tab, t_map *map);

// PRINT
void	print_grid(t_grid *grid, char *msg);
void	print_coords(t_coord *coord, char *msg);
void	print_plane(t_plane *plane, char *msg);

#endif
