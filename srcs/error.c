/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampda <cchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 16:48:47 by cchampda          #+#    #+#             */
/*   Updated: 2016/09/08 16:18:40 by cchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	check_char(char c)
{
	if (ft_isdigit(c) || c == ' ' || c == '-')
		;
	else
		FDF_ERROR;
}

void	open_file(t_info *i, char *filename)
{
	int		fd;
	char	*line;
	int		lines;
	int		c;

	c = 0;
	fd = open(filename, O_RDONLY);
	lines = count_line(filename);
	i->tab = (int **)malloc(sizeof(int *) * lines);
	ft_memset(i, 0, sizeof(i));
	while ((get_next_line(fd, &line)) > 0)
	{
		i->tab[c] = get_int_tab(line, i);
		i->bol = 1;
		if (i->y_lines != i->y_lines_check)
			FDF_ERROR;
		c++;
	}
	i->x_lines = c;
	if (i->x_lines == 0)
		FDF_ERROR;
	i->tab[c] = NULL;
	i->map_name = filename;
	init_window(i);
}

void	init_color(t_info *i, int z)
{
	if (z >= -100 && z <= 2)
	{
		i->blue = 51;
		i->green = 153;
		i->red = 255;
	}
	if (z >= 3 && z <= 15)
	{
		i->blue = 255;
		i->green = 204;
		i->red = 0;
	}
	init_color_two(i, z);
}

void	init_color_two(t_info *i, int z)
{
	if (z >= 16 && z <= 50)
	{
		i->blue = 51;
		i->green = 255;
		i->red = 51;
	}
	if (z >= 51 && z <= 75)
	{
		i->blue = 153;
		i->green = 102;
		i->red = 0;
	}
	if (z >= 76 && z <= 150)
	{
		i->blue = 255;
		i->green = 255;
		i->red = 255;
	}
}
