/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:35:41 by poriou            #+#    #+#             */
/*   Updated: 2024/03/29 15:44:22 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

//void	*mlx_new_window(t_xvar *xvar,int size_x,int size_y,char *title)
//int	mlx_key_hook(t_win_list *win,int (*funct)(),void *param)
//int			mlx_loop(t_xvar *xvar)
//int	mlx_destroy_window(t_xvar *xvar,t_win_list *win)
//int	mlx_destroy_display(t_xvar *xvar)
//int			mlx_loop_end(t_xvar *xvar)

int	handle_key_press(int keysym, t_map *map)
{
	ft_printf(1, "%d %33?\n", keysym, "is pressed!");
	if (keysym == XK_Escape)
		mlx_loop_end(map->connect);
	if (keysym == XK_Right)
		translate_right(map);
	if (keysym == XK_Left)
		translate_left(map);
	if (keysym == XK_Up)
		translate_up(map);
	if (keysym == XK_Down)
		translate_down(map);
	if (keysym == XK_KP_Add)
		zoom_in(map);
	if (keysym == XK_KP_Subtract)
		zoom_out(map);
	if (keysym == XK_u)
		rotate_up(map);
	if (keysym == XK_d)
		rotate_down(map);
	return (keysym);
}

void	open_window(t_map *map)
{
	int		wdth;
	int		hght;
	t_xvar	*co;

	wdth = map->image->img->width;
	hght = map->image->img->height;
	co = map->connect;
	co->win_list = mlx_new_window(co, wdth, hght, map->grid->name);
	if (co->win_list == 0)
		free_close_exit(map, NULL, "Problem initiationg mlx window.\n");
	mlx_put_image_to_window(map->connect, map->connect->win_list, map->image->img, 0, 0);
	ft_printf(1, "%30?\n", "Image put in window...");
	mlx_key_hook(co->win_list, &handle_key_press, map);
	mlx_hook(co->win_list, 17, 1L << 17, &mlx_loop_end, co);
	mlx_loop(co);
}
