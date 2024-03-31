/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_close_window.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:35:41 by poriou            #+#    #+#             */
/*   Updated: 2024/03/31 15:34:44 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	handle_key_press(int keysym, t_map *map)
{
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
	t_img	*im;
	t_xvar	*co;

	im = map->image->img;
	wdth = im->width;
	hght = im->height;
	co = map->connect;
	co->win_list = mlx_new_window(co, wdth, hght, map->grid->name);
	if (co->win_list == 0)
		free_close_exit(map, NULL, "Problem initiationg mlx window.\n");
	mlx_put_image_to_window(map->connect, map->connect->win_list, im, 0, 0);
	mlx_key_hook(co->win_list, &handle_key_press, map);
	mlx_hook(co->win_list, 17, 1L << 17, &mlx_loop_end, co);
	mlx_loop(co);
}
