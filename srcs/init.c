/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampda <cchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/30 16:49:08 by cchampda          #+#    #+#             */
/*   Updated: 2016/05/31 14:53:13 by cchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

void	init_co(t_info *i)
{
	i->x = 0;
	i->y = 0;
}

void	init_para(t_info *i)
{
	i->deep = 10;
	i->y_place = HGT / 4;
	i->x_place = WDT / 2;
	i->zoom = 10.0;
	i->mode = 0;
	i->flat = 0.80;
}

void	init_window(t_info *i)
{
	i->mlx = mlx_init();
	i->win = mlx_new_window(i->mlx, WDT, HGT, "Window");
	init_para(i);
	put_calc_img(i);
	mlx_hook(i->win, 2, 3, ft_key_print, i);
	mlx_loop(i->mlx);
}

void	put_calc_img(t_info *i)
{
	i->mlx_img = mlx_new_image(i->mlx, WDT, HGT);
	i->ptr_img = mlx_get_data_addr(i->mlx_img, &(i->bpp), &(i->sl), &(i->ian));
	init_co(i);
	print_map(i);
	mlx_put_image_to_window(i->mlx, i->win, i->mlx_img, 0, 0);
	menu(i);
	mlx_destroy_image(i->mlx, i->ptr_img);
}
