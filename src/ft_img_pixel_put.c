/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_img_pixel_put.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 16:29:13 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/04 21:28:05 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_img_pixel_put(t_sav *all, int x, int y, int rgb)
{
	int				bpp;
	int				sl;
	int				en;
	char			*imag;
	unsigned int	tmp;

	imag = mlx_get_data_addr(all->img, &bpp, &sl, &en);
	tmp = (mlx_get_color_value(all->mlx, rgb));
	if (x > 0 && x < all->win_size_x && y > 0 && y < all->win_size_y)
		ft_memcpy((void *)((imag + y * all->win_size_x *
						(bpp / 8) + x * (bpp / 8))), (void *)&tmp, 4);
}
