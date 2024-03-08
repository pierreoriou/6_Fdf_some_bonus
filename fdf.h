/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:22:00 by poriou            #+#    #+#             */
/*   Updated: 2024/03/07 13:05:21 by poriou           ###   ########.fr       */
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
	int		grid_len;
	int		grid_width;
	int		max_altitude;
	int		max_depth;
}			t_grid;

int		main(int argc, char *argv[]);
void	check_file_errors(char *arg);
void	parse_file(char *filename);
void	init_grid(t_grid *grid, char *filename);
void	open_window(t_xvar **connect, char *filename);
// UTILS
void	free_close_exit(char *str, int fd, char *err_msg);
void	clean_and_exit(t_xvar **connect);
int		get_tab_len(char **tab);
// PRINT
void	print_grid(t_grid *grid);

#endif
