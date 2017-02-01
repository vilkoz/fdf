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

void	ft_draw_line(t_sav *all, int x0, int y0, int x1, int y1, int rgb)
{
	int dx = abs(x1 - x0);
	int dy = abs(y1 - y0);
	int sx = x1 >= x0 ? 1 : -1;
	int sy = y1 >= y0 ? 1 : -1;

	if (dy <= dx)
	{
		int d = (dy << 1) - dx;
		int d1 = dy << 1;
		int d2 = (dy - dx) << 1;
		mlx_pixel_put(all->mlx, all->win, x0, y0, rgb);
		for(int x = x0 + sx, y = y0, i = 1; i <= dx; i++, x += sx)
		{
			if ( d >0)
			{
				d += d2;
				y += sy;
			}
			else
				d += d1;
			mlx_pixel_put(all->mlx, all->win, x, y, rgb);
		}
	}
	else
	{
		int d = (dx << 1) - dy;
		int d1 = dx << 1;
		int d2 = (dx - dy) << 1;
		mlx_pixel_put(all->mlx, all->win, x0, y0, rgb);
		for(int y = y0 + sy, x = x0, i = 1; i <= dy; i++, y += sy)
		{
			if ( d >0)
			{
				d += d2;
				x += sx;
			}
			else
				d += d1;
			mlx_pixel_put(all->mlx, all->win, x, y, rgb);
		}
	}
}
