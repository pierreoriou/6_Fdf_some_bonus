/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file_errors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poriou <poriou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 10:23:19 by poriou            #+#    #+#             */
/*   Updated: 2024/03/04 14:49:49 by poriou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	check_file_extension(char *file)
{
	int	len;

	len = ft_strlen(file);
	if (ft_strncmp(file + (len - 4), ".fdf", 4) != 0)
		free_close_exit(file, -1, "Wrong file extension\n");
}

static int	check_content_format(char *content)
{
	int	i;

	i = 0;
	if ((content[i] == '+' || content[i] == '-') && ft_isdigit(content[i + 1]))
		i++;
	while (ft_isdigit(content[i]))
		i++;
	if (content[i] == '\0')
		return (1);
	if (ft_strncmp(content + i, ",0x", 3) == 0)
	{
		i += 3;
		if (ft_strlen(content + i) < 2 || ft_strlen(content + i) > 6)
		{
			return (0);
		}
		while (ft_ischarset(content[i], "123456789abcdefABCDEF"))
			i++;
		if (i != (int)ft_strlen(content))
			return (0);
	}
	else
		return (0);
	return (1);
}

static int	check_line_content(char **tab, char *str, int fd, int elems)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (!check_content_format(tab[i]))
		{
			ft_free_tab(tab);
			free_close_exit(str, fd, "File contains wrong data format.\n");
		}
		i++;
	}
	if (i != elems)
	{
		ft_free_tab(tab);
		free_close_exit(str, fd, "File contains unequal data per line.\n");
	}
	return (i);
}

static void	check_file_content(int fd)
{
	char	*str;
	char	**tab;
	int		elems;

	tab = NULL;
	str = get_next_line(fd);
	if (!str)
		free_close_exit(str, fd, "No content in file.\n");
	tab = ft_split(str, " \n");
	free (str);
	elems = get_tab_len(tab);
	check_line_content(tab, str, fd, elems);
	ft_free_tab(tab);
	while (str != NULL)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		tab = ft_split(str, " \n");
		check_line_content(tab, str, fd, elems);
		free (str);
		ft_free_tab(tab);
	}
	printf("Number of elems per line = %d\n", elems);
	free (str);
}

void	check_file_errors(char *filename)
{
	char	*trim_filename;
	int		fd;

	trim_filename = ft_strtrim(filename, " \t\n\v\f\r");
	if (ft_strlen(trim_filename) < 5)
		free_close_exit(trim_filename, -1, "Invalid file name.\n");
	check_file_extension(trim_filename);
	free (trim_filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		exit (EXIT_FAILURE);
	check_file_content(fd);
	close (fd);
}
