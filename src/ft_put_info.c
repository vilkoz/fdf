/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 17:26:17 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/06 14:00:35 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_putstr_y(t_sav *all, char *str)
{
	all->txt_shift += 15;
	mlx_string_put(all->mlx, all->win, 15, all->txt_shift, 0xffffff, str);
}

int			return_ang(int ang)
{
	while (ang > 360)
		ang -= 360;
	while (ang < -360)
		ang += 360;
	if (ang < -180 && ang > -360)
		ang += 360;
	if (ang > 180 && ang < 360)
		ang -= 360;
	return (ang);
}

void		ft_put_info(t_sav *all)
{
	ft_putstr_y(all, "Coords:");
	ft_putstr_y(all, ft_strjoin(ft_strjoin("x: ", ft_itoa(all->x_shift)),
				ft_strjoin("    y: ", ft_itoa(all->y_shift))));
	ft_putstr_y(all, "Angles:");
	ft_putstr_y(all, ft_strjoin(ft_strjoin("alpha: ",
					ft_itoa(return_ang((int)(all->alfa / RAD)))),
				ft_strjoin("    gamma: ",
					ft_itoa(return_ang((int)(all->gama / RAD))))));
	ft_putstr_y(all, ft_strjoin("Zoom: ", ft_itoa((int)(all->zoom * 100))));
	ft_putstr_y(all, ft_strjoin("Height: ", ft_itoa((all->mult_z))));
	ft_putstr_y(all, "Controls:");
	ft_putstr_y(all, " arrows - change angle");
	ft_putstr_y(all, " WASD   - move");
	ft_putstr_y(all, " RGB    - change color");
	ft_putstr_y(all, " +-     - zoom");
	ft_putstr_y(all, " []     - resize height");
	ft_putstr_y(all, ft_strjoin("k.iso = ", ft_itoa(all->keys.iso)));
	ft_putstr_y(all, "Angles:");
	ft_putstr_y(all, ft_strjoin(ft_strjoin("salpha: ",
					ft_itoa(return_ang((int)(all->s_alfa / RAD)))),
				ft_strjoin("    sgamma: ",
					ft_itoa(return_ang((int)(all->s_gama / RAD))))));
	all->txt_shift = 0;
}
