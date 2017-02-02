/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_draw_line.c										:+:		 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: vrybalko <marvin@42.fr>					+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+			  */
/*	 Created: 2017/02/01 12:53:53 by vrybalko		   #+#	  #+#			  */
/*	 Updated: 2017/02/01 12:53:53 by vrybalko		  ###	########.fr		  */
/*																			  */
/* ************************************************************************** */

#include "fdf.h"

t_lin	*line_init(t_lst *p1, t_lst *p2, int type)
{
	t_lin	*lin;

	lin = (t_lin *)malloc(sizeof(t_lin));
	lin->dx = abs(p2->x - p1->x);
	lin->dy = abs(p2->y - p1->y);
	lin->sx = p2->x >= p1->x ? 1 : -1;
	lin->sy = p2->y >= p1->y ? 1 : -1;
	lin->p1 = p1;
	lin->p2 = p2;
	if (type == 1)
	{
		lin->d = (lin->dy << 1) - lin->dx;
		lin->d1 = lin->dy << 1;
		lin->d2 = (lin->dy - lin->dx) << 1;
	}
	else
	{
		lin->d = (lin->dx << 1) - lin->dy;
		lin->d1 = lin->dx << 1;
		lin->d2 = (lin->dx - lin->dy) << 1;
	}
	return (lin);
}

void	draw_type1(t_sav *all, t_lin *lin)
{
	int x;
	int	y;
	int	i;

	x = lin->p1->x + lin->sx;
	y = lin->p1->y;
	i = 1;
	mlx_pixel_put(all->mlx, all->win, lin->p1->x, lin->p1->y, lin->p1->rgb);
	while(i <= lin->dx)
	{
		if (lin->d > 0)
		{
			lin->d += lin->d2;
			y += lin->sy;
		}
		else
			lin->d += lin->d1;
		mlx_pixel_put(all->mlx, all->win, x, y, lin->p1->rgb);
		i++;
		x += lin->sx;
	}
}

void	draw_type2(t_sav *all, t_lin *lin)
{
	int x;
	int	y;
	int	i;

	y = lin->p1->y + lin->sy;
	x = lin->p1->x;
	i = 1;
	mlx_pixel_put(all->mlx, all->win, lin->p1->x, lin->p1->y, lin->p1->rgb);
	while(i <= lin->dy)
	{
		if (lin->d > 0)
		{
			lin->d += lin->d2;
			x += lin->sx;
		}
		else
			lin->d += lin->d1;
		mlx_pixel_put(all->mlx, all->win, x, y, lin->p1->rgb);
		i++;
		y += lin->sy;
	}
}

void	ft_draw_line(t_sav *all, t_lst *p1, t_lst *p2)
{
	if (abs(p2->y - p1->y) <= abs(p2->x - p1->x))
		draw_type1(all, line_init(p1, p2, 1));
	else
		draw_type2(all, line_init(p1, p2, 2));
}
