/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchampda <cchampda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 16:34:14 by cchampda          #+#    #+#             */
/*   Updated: 2016/09/08 15:49:33 by cchampda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/fdf.h"

int		main(int ac, char **av)
{
	t_info *i;

	i = malloc(sizeof(t_info));
	if (ac != 2 && !(av[1]))
		USAGE_ERROR;
	if (!ft_strstr(av[1], ".fdf"))
		FDF_ERROR;
	if (ac == 2 && av[1])
		open_file(i, av[1]);
}
