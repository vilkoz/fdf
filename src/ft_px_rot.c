/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_px_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:49:20 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/05 21:37:48 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_iso(t_sav *all, int *x, int *y, int *z)
{
	int		x1;
	int		y1;
	int		z1;

	x1 = *x - (all->win_size_x / 2);
	y1 = *y - (all->win_size_y / 2);
	z1 = -(*z);
	*x = (x1 * cos(all->beta) + (-y1 * sin(all->alfa) + z1 * cos(all->alfa))
		* sin(all->beta)) * cos(all->gama) + (y1 * cos(all->alfa)
		+ z1 * sin(all->alfa)) * sin(all->gama) + (all->win_size_x / 2);
	*y = -(x1 * cos(all->beta) + (-y1 * sin(all->alfa) + z1 * cos(all->alfa))
		* sin(all->beta)) * sin(all->gama) + (y1 * cos(all->alfa)
		+ z1 * sin(all->alfa)) * cos(all->gama) + (all->win_size_y / 2);
}
/*
static void		ft_persp(t_sav *all, int *x, int *y, int *z)
{
	int		x1;
	int		y1;
	int		z1;

	x1 = *x - (all->win_size_x / 2) + 1000;
	y1 = *y - (all->win_size_y / 2) + 0;
	z1 = -(*z) + 1000;
	// x = alfa, y = beta, z = gama,
	int dz = cos(all->alfa) * (cos(all->beta) * z1 + sin(all->beta)
		* (sin(all->gama) * y1 + cos(all->gama) * x1)) - sin(all->alfa)
		* (cos(all->gama) * y1 - sin(all->gama) * x1);
	int dx = cos(all->beta) * (sin(all->gama) * y1 + cos(all->gama) * x1) - z1 * sin(all->beta);
	int	dy = sin(all->alfa) * (cos(all->beta) * z1 + sin(all->beta)
		* (sin(all->gama) * y1 + cos(all->gama) * x1)) + cos(all->alfa)
		* (cos(all->gama) * y1 - sin(all->gama) * x1);
	int ex = 1000, ey = 1000, ez = 0;
	if (dz != 0)
	{
		*x = (ez / dz) * dx - ex;
		*y = (ez / dz) * dy - ey;
	}
	else
	{
		*x = 10000;
		*y = 10000;
	}
}
*/
t_sav			*ft_px_rot(t_sav *all)
{
	t_lst	*tmp;
	t_lst	*head;
	int		mult_x;
	int		mult_y;

	tmp = all->lst;
	head = tmp;
	mult_x = (int)round((all->win_size_x / all->size_x) * all->zoom);
	mult_y = (int)round((all->win_size_y / all->size_y) * all->zoom);
	while (tmp)
	{
		tmp->x = tmp->x1 * mult_x + all->x_shift;
		tmp->y = tmp->y1 * mult_y + all->y_shift;
		tmp->z = (int)round(tmp->z1 * all->mult_z * all->zoom);
		tmp->rgb += all->rgb_shift;
		ft_iso(all, &(tmp->x), &(tmp->y), &(tmp->z));
		tmp = tmp->next;
	}
	all->rgb_shift = 0;
	all->lst = head;
	return (all);
}
