/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trace.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampda <cchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 16:48:58 by cchampda          #+#    #+#             */
/*   Updated: 2016/05/31 14:53:14 by cchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void		put_pixel_to_image(int x, int y, t_info *i)
{
	if (x < WDT && y < HGT && x > 0 && y > 0)
	{
		i->ptr_img[(i->sl * y) + (4 * x) + 2] = i->blue;
		i->ptr_img[(i->sl * y) + (4 * x) + 1] = i->green;
		i->ptr_img[(i->sl * y) + (4 * x)] = i->red;
	}
}

t_point		calcul(int x, int y, int z, t_info *i)
{
	t_point point;

	if (i->mode == 0)
	{
		point.x = i->x_place + ((sqrt(2.0) / 2.0) * ((x * i->zoom) -\
		(y * i->zoom)));
		point.y = i->y_place - ((sqrt(2.0 / 2.0) * (z * i->zoom / i->deep)) -
		((i->flat / sqrt(9.0)) * (i->zoom * (x + y))));
		return (point);
	}
	else
	{
		point.x = i->x_place + ((x * i->zoom) + i->flat * (y * i->zoom));
		point.y = i->y_place -\
			((z * i->zoom / i->deep) - i->flat * (y * i->zoom));
		return (point);
	}
}

void		print_trace(t_point p1, t_point p2, t_info *i)
{
	i->dx = abs((p2.x - p1.x));
	i->sx = p1.x < p2.x ? 1 : -1;
	i->dy = abs((p2.y - p1.y));
	i->sy = p1.y < p2.y ? 1 : -1;
	i->err = (i->dx > i->dy ? i->dx : -i->dy) / 2;
	while (!(p1.x == p2.x && p1.y == p2.y))
	{
		put_pixel_to_image(p1.x, p1.y, i);
		i->err2 = i->err;
		if (i->err2 > -i->dx)
		{
			i->err -= i->dy;
			p1.x += i->sx;
		}
		if (i->err2 < i->dy)
		{
			i->err += i->dx;
			p1.y += i->sy;
		}
	}
}

void		print_map(t_info *s)
{
	t_point p1;
	t_point p2;

	while (s->y < s->x_lines)
	{
		while (s->x < s->y_lines)
		{
			p1 = calcul(s->x, s->y, s->tab[s->y][s->x], s);
			s->x++;
			init_color(s, s->tab[s->y][s->x]);
			if (s->x < s->y_lines)
			{
				p2 = calcul(s->x, s->y, s->tab[s->y][s->x], s);
				print_trace(p1, p2, s);
			}
			if (s->y < s->x_lines - 1)
			{
				p2 = calcul(s->x - 1, s->y + 1, s->tab[s->y + 1][s->x - 1], s);
				print_trace(p1, p2, s);
			}
		}
		s->x = 0;
		s->y++;
	}
}
