/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 17:26:17 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/06 17:28:46 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_putstry(t_sav *all, char *str)
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
	if (all->alfa == 90 * RAD && all->beta == 70.5 * RAD &&
			all->gama == -60 * RAD)
		ft_putstry(all, "Projection = iso");
	else
		ft_putstry(all, "Projection = parallel");
	ft_putstry(all, "Coords:");
	ft_putstry(all, ft_strjoin(ft_strjoin("x: ", ft_itoa(all->x_shift)),
				ft_strjoin("    y: ", ft_itoa(all->y_shift))));
	ft_putstry(all, "Angles:");
	ft_putstry(all, ft_strjoin(ft_strjoin("alpha: ",
					ft_itoa(return_ang((int)(all->alfa / RAD)))),
				ft_strjoin("    gamma: ",
					ft_itoa(return_ang((int)(all->gama / RAD))))));
	ft_putstry(all, ft_strjoin("beta: ", ft_itoa(return_ang(all->beta / RAD))));
	ft_putstry(all, ft_strjoin("Zoom: ", ft_itoa((int)(all->zoom * 100))));
	ft_putstry(all, ft_strjoin("Height: ", ft_itoa((all->mult_z))));
	ft_putstry(all, "Controls:");
	ft_putstry(all, " arrows - change angle");
	ft_putstry(all, " WASD   - move");
	ft_putstry(all, " RGB    - change color");
	ft_putstry(all, " +-     - zoom");
	ft_putstry(all, " []     - resize height");
	ft_putstry(all, " p      - enable iso");
	all->txt_shift = 0;
}
