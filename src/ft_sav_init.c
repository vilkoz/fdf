/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sav_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:51:09 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/01 13:16:34 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_sav	*ft_sav_init(char *title)
{
	t_sav	*all;

	all = (t_sav *)malloc(sizeof(t_sav));
	all->mlx = mlx_init();
	all->winSizeX = 400;
	all->winSizeY = 400;
	all->win = mlx_new_window(all->mlx, all->winSizeX, all->winSizeY, title);
	all->sizeX = -1;
	all->sizeY = -1;
	all->lst = NULL;
	return (all);
}
