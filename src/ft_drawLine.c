/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_drawLine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 17:17:26 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/02 21:19:19 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_lin	*line_init(t_lst *p1, t_lst *p2)
{
	t_lin	*lin;

	lin = (t_lin *)malloc(sizeof(t_lin));
	lin->dx = abs(p2->x - p1->x);
	lin->dy = abs(p2->y - p1->y);
	lin->sx = p1->x < p2->x ? 1 : -1;
	lin->sy = p1->y < p2->y ? 1 : -1;
	lin->error = lin->dx - lin->dy;
	lin->drgb = abs(p2->rgb - p1->rgb) /
		sqrt(lin->dx * lin->dx + lin->dy * lin->dy);
	return (lin);
}

void		drawLine(t_sav *all, t_lst *p1, t_lst *p2)
{
	t_lin	*lin;
	int		x1;
	int		y1;
	int		color;

	x1 = p1->x;
	y1 = p1->y;
	lin = line_init(p1, p2);
	color = p1->rgb;
	mlx_pixel_put(all->mlx, all->win, x1, y1, color);
	while (x1 != p2->x || y1 != p2->y) 
	{
		mlx_pixel_put(all->mlx, all->win, x1, y1, color);
		lin->error2 = lin->error * 2;
		if (lin->error2 > -lin->dy) 
		{
			lin->error -= lin->dy;
			x1 += lin->sx;
		}
		if (lin->error2 < lin->dx) 
		{
			lin->error += lin->dx;
			y1 += lin->sy;
		}
		color = (p1->rgb >= p2->rgb) ? color - lin->drgb : color + lin->drgb;
	}
}
