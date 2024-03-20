/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:35:41 by poriou            #+#    #+#             */
/*   Updated: 2024/03/20 18:49:04 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//void	*mlx_new_window(t_xvar *xvar,int size_x,int size_y,char *title)
//int	mlx_key_hook(t_win_list *win,int (*funct)(),void *param)
//int			mlx_loop(t_xvar *xvar)
//int	mlx_destroy_window(t_xvar *xvar,t_win_list *win)
//int	mlx_destroy_display(t_xvar *xvar)
//int			mlx_loop_end(t_xvar *xvar)

void	close_window(t_xvar **connect)
{
	mlx_destroy_window(*connect, (*connect)->win_list);
	mlx_loop_end(*connect);
}

int	handle_esc_press(int keysym, t_xvar *connect)
{
	if (keysym == XK_Escape)
	{
		ft_printf(1, "%d %32?\n", keysym, "is pressed, and window is closed!");
		close_window(&connect);
	}
	ft_printf(1, "%d %33?\n", keysym, "is pressed!");
	return (keysym);
}

void	open_window(t_xvar **connect, char *file)
{
	int		win_wdth;
	int		win_hgt;

	win_wdth = 960;
	win_hgt = 540;
	*connect = mlx_init();
	if (*connect == 0)
		clean_and_exit(connect);
	(*connect)->win_list = mlx_new_window(*connect, win_wdth, win_hgt, file);
	if ((*connect)->win_list == 0)
		clean_and_exit(connect);
	mlx_key_hook((*connect)->win_list, &handle_esc_press, *connect);
	mlx_loop(*connect);
}
