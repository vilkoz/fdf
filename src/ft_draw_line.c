/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:12:58 by vrybalko          #+#    #+#             */
/*   Updated: 2017/03/27 16:27:06 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_rgb	init_rgb(int rgb)
{
	t_rgb	new;

	new.r = (rgb >> 16);
	new.g = (rgb >> 8) - ((int)new.r << 8);
	new.b = rgb - ((rgb >> 8) << 8);
	return (new);
}

static int		con_rgb(t_rgb c)
{
	return (((int)c.r << 16) + ((int)c.g << 8) + (int)c.b);
}

static t_rgb	calc_rgb(t_rgb c1, t_rgb c2, char op)
{
	t_rgb	res;

	res = init_rgb(0);
	if (op == '+')
	{
		res.r = c1.r + c2.r;
		res.g = c1.g + c2.g;
		res.b = c1.b + c2.b;
	}
	if (op == '-')
	{
		res.r = c1.r - c2.r;
		res.g = c1.g - c2.g;
		res.b = c1.b - c2.b;
	}
	return (res);
}

static t_lin	line_init(t_lst *p1, t_lst *p2)
{
	t_lin	lin;
	t_rgb	c;
	double	len;

	lin.dx = abs(p2->x - p1->x);
	lin.dy = abs(p2->y - p1->y);
	lin.sx = p1->x < p2->x ? 1 : -1;
	lin.sy = p1->y < p2->y ? 1 : -1;
	lin.error = lin.dx - lin.dy;
	c = calc_rgb(init_rgb(p2->rgb), init_rgb(p1->rgb), '-');
	len = sqrt(lin.dx * lin.dx + lin.dy * lin.dy);
	c.r /= len;
	c.g /= len;
	c.b /= len;
	lin.drgb = c;
	return (lin);
}

void			ft_draw_line(t_sav *all, t_lst *p1, t_lst *p2)
{
	t_lin	lin;
	int		x1;
	int		y1;
	t_rgb	color;

	x1 = p1->x;
	y1 = p1->y;
	lin = line_init(p1, p2);
	color = init_rgb(p1->rgb);
	while (x1 != p2->x || y1 != p2->y)
	{
		ft_img_pixel_put(all, x1, y1, con_rgb(color));
		lin.error2 = lin.error * 2;
		if (lin.error2 > -lin.dy)
		{
			lin.error -= lin.dy;
			x1 += lin.sx;
		}
		if (lin.error2 < lin.dx)
		{
			lin.error += lin.dx;
			y1 += lin.sy;
		}
		color = calc_rgb(color, lin.drgb, '+');
	}
}
