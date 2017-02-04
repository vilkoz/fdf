/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose_angle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 18:44:29 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/04 15:10:13 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static int	expose_hook(void *all)
{
	ft_px_put(all);
	return (0);
}

static void	real_choose(int key, int *alfa, int *beta)
{
	if (key == 123)
		*beta = 10;
	if (key == 124)
		*beta = -10;
	if (key == 125)
		*alfa = 10;
	if (key == 126)
		*alfa = -10;
}

void		ft_choose_angle(int key, void *all)
{
	int		alfa;
	int		beta;

	alfa = 0;
	beta = 0;
	real_choose(key, &alfa, &beta);
	ft_win_clear((t_sav *)all);
	ft_px_put(ft_px_rot((t_sav *)all, alfa, beta));
	ft_putstr("printing..\n");
	mlx_expose_hook(((t_sav *)all)->win, expose_hook, all);
}
