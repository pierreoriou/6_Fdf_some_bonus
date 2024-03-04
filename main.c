/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 11:21:32 by poriou            #+#    #+#             */
/*   Updated: 2024/03/04 17:45:46 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		ft_printf(2, "Usage: %s <argument1>\n", argv[0]);
		exit (EXIT_FAILURE);
	}
	check_file_errors(argv[1]);
	parse_file(argv[1]);
	ft_printf(1, "%32?\n", "Seems like everything went smoothly.");
	return (0);
}
