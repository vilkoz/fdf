/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sav_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:51:09 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/04 16:41:36 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_sav	*ft_sav_init(int z, char *title)
{
	t_sav	*all;

	all = (t_sav *)malloc(sizeof(t_sav));
	all->mlx = mlx_init();
	all->win_size_x = 1300;
	all->win_size_y = 1300;
	all->win = mlx_new_window(all->mlx, all->win_size_x,
			all->win_size_y, title);
	all->img = mlx_new_image(all->mlx, all->win_size_x,
			all->win_size_y);
	all->size_x = -1;
	all->size_y = -1;
	all->lst = NULL;
	all->mult_z = z;
	all->alfa = 60 * RAD;
	all->beta = 40 * RAD;
	all->gama = -60 * RAD;
	return (all);
}
