/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_px_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 12:17:24 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/04 15:14:16 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_iso(t_sav *all, int *x, int *y, int z)
{
	int		x1;
	int		y1;
	int		z1;

	x1 = *x - (all->win_size_x / 2);
	y1 = *y - (all->win_size_y / 2);
	z1 = -(z) * all->mult_z;
	*x = (x1 * cos(all->beta) + (-y1 * sin(all->alfa) + z1 * cos(all->alfa))
		* sin(all->beta)) * cos(all->gama) + (y1 * cos(all->alfa)
		+ z1 * sin(all->alfa)) * sin(all->gama) + (all->win_size_x / 2);
	*y = -(x1 * cos(all->beta) + (-y1 * sin(all->alfa) + z1 * cos(all->alfa))
		* sin(all->beta)) * sin(all->gama) + (y1 * cos(all->alfa)
		+ z1 * sin(all->alfa)) * cos(all->gama) + (all->win_size_y / 2);
}

t_sav			*ft_px_transform(t_sav *all)
{
	int		step_x;
	int		step_y;
	t_lst	*tmp;
	t_lst	*head;

	step_x = all->win_size_x / all->size_x;
	step_y = all->win_size_y / all->size_y;
	tmp = all->lst;
	head = tmp;
	while (tmp)
	{
		tmp->x *= step_x;
		tmp->y *= step_y;
		ft_iso(all, &(tmp->x), &(tmp->y), tmp->z);
		tmp = tmp->next;
	}
	all->lst = head;
	return (all);
}
