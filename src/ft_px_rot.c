/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_px_rot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <vrybalko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:49:20 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/18 14:22:36 by vrybalko         ###   ########.fr       */
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
	*x = (x1 * all->b.cos + (-y1 * all->a.sin + z1 * all->a.cos)
		* all->b.sin) * all->g.cos + (y1 * all->a.cos
		+ z1 * all->a.sin) * all->g.sin + (all->win_size_x / 2);
	*y = -(x1 * all->b.cos + (-y1 * all->a.sin + z1 * all->a.cos)
		* all->b.sin) * all->g.sin + (y1 * all->a.cos
		+ z1 * all->a.sin) * all->g.cos + (all->win_size_y / 2);
}

void			save_angles(t_sav *all)
{
	all->s_alfa = all->alfa;
	all->s_beta = all->beta;
	all->s_gama = all->gama;
}

void			rest_angles(t_sav *all)
{
	all->alfa = all->s_alfa;
	all->beta = all->s_beta;
	all->gama = all->s_gama;
}

void			make_iso(t_sav *all)
{
	if (all->keys.iso == 1)
	{
		if (all->alfa != 90 * RAD && all->beta != 70.5 * RAD &&
				all->gama != -60 * RAD)
		{
			save_angles(all);
			all->alfa = 90 * RAD;
			all->beta = 70.5 * RAD;
			all->gama = -60 * RAD;
		}
	}
	if (all->keys.iso == 0)
	{
		rest_angles(all);
		all->keys.iso = 2;
	}
}

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
	all->a = calc_sin_cos(all->alfa);
	all->b = calc_sin_cos(all->beta);
	all->g = calc_sin_cos(all->gama);
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
