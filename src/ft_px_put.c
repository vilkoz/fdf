/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_px_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 20:49:00 by vrybalko          #+#    #+#             */
/*   Updated: 2017/01/31 21:27:56 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_px_put(t_sav *all)
{
	int		stepX;
	int		stepY;
	t_lst	*tmp;

	stepX = all->winSizeX / all->sizeX;
	stepY = all->winSizeY / all->sizeY;
	tmp = all->lst;
	while (tmp)
	{
		tmp->x *= stepX;
		tmp->y *= stepY;
		mlx_pixel_put(all->mlx, all->win, tmp->x, tmp->y, tmp->rgb);
		tmp = tmp->next;
	}
	mlx_loop(all->mlx);
}
