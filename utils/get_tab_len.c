/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tab_len.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 11:34:53 by poriou            #+#    #+#             */
/*   Updated: 2024/03/20 10:40:12 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_tab_len(char **tab, t_map *map)
{
	int	len;

	if (!tab || !*tab)
		return (0);
	len = 0;
	while (tab[len])
		len++;
	ft_printf(1, "%30? len = %d\n", "In get tab len", len);
	ft_printf(1, "%30? map->grid.len = %d\n", "In get tab map->grid.len", map->grid.len);
	if (map->grid.len == 0)
	{
		map->grid.len = len;
		return (len);
	}
	else if (map->grid.len != len)
		return (0);
	return (len);
}
