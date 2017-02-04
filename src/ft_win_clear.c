/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 18:32:18 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/04 15:15:26 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_win_clear(t_sav *all)
{
	int		i;
	int		j;

	i = -1;
	j = -1;
	while (++i < all->win_size_y)
	{
		while (++j < all->win_size_x)
			mlx_pixel_put(all->mlx, all->win, j, i, 0x00000000);
		j = -1;
	}
}
