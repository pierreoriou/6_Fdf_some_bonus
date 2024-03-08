/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_and_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 11:58:51 by poriou            #+#    #+#             */
/*   Updated: 2024/03/07 13:05:10 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	clean_and_exit(t_xvar **connect)
{
	// int	mlx_destroy_window(t_xvar *xvar,t_win_list *win)
	if ((*connect)->win_list != 0)
		mlx_destroy_window(connect, (*connect)->win_list);
	if (connect != 0)
		mlx_loop_end(connect);
	exit (EXIT_FAILURE);
}
