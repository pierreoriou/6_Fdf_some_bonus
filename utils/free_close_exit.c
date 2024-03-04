/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_close_exit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:54:23 by poriou            #+#    #+#             */
/*   Updated: 2024/03/04 18:19:32 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	free_close_exit(char *str, int fd, char *err_msg)
{
	free (str);
	if (fd != -1)
		close (fd);
	ft_printf(2, "%31?", err_msg);
	exit (EXIT_FAILURE);
}
