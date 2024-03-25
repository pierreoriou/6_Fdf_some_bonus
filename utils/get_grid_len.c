/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_grid_len.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: peoriou <peoriou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:34:53 by poriou            #+#    #+#             */
/*   Updated: 2024/03/23 11:46:19 by peoriou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_grid_len(char **tab, t_map *map)
{
	int	len;

	if (!tab || !*tab)
		return (0);
	len = 0;
	while (tab[len])
		len++;
	if (map->grid->len == 0)
	{
		map->grid->len = len;
		return (len);
	}
	else if (map->grid->len != len)
		return (0);
	return (len);
}
