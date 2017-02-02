/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_px_put.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 20:49:00 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/02 20:48:37 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_px_put(t_sav *all)
{
	t_lst	*tmp;

	all = ft_px_transform(all);
	tmp = all->lst;
	while (tmp)
	{
		mlx_pixel_put(all->mlx, all->win, tmp->x, tmp->y, tmp->rgb);
		tmp = tmp->next;
	}
	ft_connect_px(all);
	mlx_loop(all->mlx);
}
