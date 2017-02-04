/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_px_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:49:20 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/04 15:09:06 by vrybalko         ###   ########.fr       */
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

t_sav			*ft_px_rot(t_sav *all, double alfa, double beta)
{
	t_lst	*tmp;
	t_lst	*head;

	tmp = all->lst;
	head = tmp;
	all->alfa += alfa * RAD;
	all->gama += beta * RAD;
	while (tmp)
	{
		tmp->x = tmp->x1 * (all->win_size_x / all->size_x);
		tmp->y = tmp->y1 * (all->win_size_y / all->size_y);
		tmp->z = tmp->z1 * all->mult_z;
		ft_iso(all, &(tmp->x), &(tmp->y), &(tmp->z));
		tmp = tmp->next;
	}
	all->lst = head;
	return (all);
}
