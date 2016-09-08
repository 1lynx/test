/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampda <cchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 16:35:26 by cchampda          #+#    #+#             */
/*   Updated: 2016/05/31 14:54:59 by cchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

# define HGT 1000
# define WDT 1500
# define BUF_SIZE 1000
# define FDF_ERROR { ft_putstr("Error, invalid file"); exit(-1); }
# define USAGE_ERROR { perror("Error"); return(-1); }

typedef struct	s_info
{
	void		*mlx;
	void		*win;
	void		*mlx_img;
	char		*ptr_img;
	int			x_lines;
	int			y_lines;
	int			y_lines_check;
	int			**tab;
	int			x_place;
	int			y_place;
	float		zoom;
	int			deep;
	float		flat;
	float		red;
	float		green;
	float		blue;
	int			bpp;
	int			sl;
	int			ian;
	int			mode;
	int			x;
	int			y;
	int			dx;
	int			sx;
	int			dy;
	int			sy;
	int			err;
	int			err2;
	char		*map_name;
	int			bol;
}				t_info;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

int				count_col(char **tab, t_info *s);
int				count_line(char *av);
int				*get_int_tab(char *str, t_info *s);
void			init_para(t_info *i);
void			init_window(t_info *i);
void			put_calc_img(t_info *i);
void			init_color(t_info *s, int z);
void			put_pixel_to_image(int x, int y, t_info *i);
t_point			calcul(int x, int y, int z, t_info *i);
void			print_trace(t_point p1, t_point p2, t_info *i);
void			print_map(t_info *i);
int				ft_key_print(int key, t_info *i);
void			menu(t_info *s);
void			init_co(t_info *i);
void			open_file(t_info *i, char *filename);
void			check_char(char c);
void			r_menu(t_info *i);
void			l_menu(t_info *i);
void			para_change(t_info *i, int key);
void			init_color_two(t_info *i, int z);

#endif
