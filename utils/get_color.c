/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 15:57:38 by peoriou           #+#    #+#             */
/*   Updated: 2024/03/29 14:28:10 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static char	*standardize_color(char *color)
{
	int	i;

	i = 0;
	while (color[i])
	{
		color[i] = ft_tolower(color[i]);
		i++;
	}
	return (color);
}

int	get_color(char *elem)
{
	int		i;
	int		color;
	char	*color_str;
	char	*hexa_base;

	if (!ft_ischarset(',', elem))
		return (16777215);
	i = 0;
	hexa_base = "0123456789abcdef";
	while (elem[i])
	{
		if (ft_strncmp(elem + i, ",0x", 3) == 0)
		{
			i += 3;
			color_str = standardize_color(elem + i);
			color = (int)ft_atol_base(color_str, hexa_base);
			return (color);
		}
		i++;
	}
	return (16777215);
}
