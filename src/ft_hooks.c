/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 14:25:26 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/05 21:37:50 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_press(int key, t_key *k)
{
	(key == 33) ? k->z_re_u = 1 : (void)k->gopa;
	(key == 30) ? k->z_re_d = 1 : (void)k->gopa;
	(key == 15) ? k->r_shi = 1 : (void)k->gopa;
	(key == 5) ? k->g_shi= 1 : (void)k->gopa;
	(key == 11) ? k->b_shi= 1 : (void)k->gopa;
	(key == 13) ? k->y_shift_up = 1 : (void)k->gopa;
	(key == 0) ? k->x_shift_down = 1 : (void)k->gopa;
	(key == 1) ? k->y_shift_down = 1 : (void)k->gopa;
	(key == 2) ? k->x_shift_up = 1 : (void)k->gopa;
	(key == 24) ? k->zoom_in = 1 : (void)k->gopa;
	(key == 27) ? k->zoom_out = 1 : (void)k->gopa;
	(key == 53) ? k->esc = 1 : (void)k->gopa;
	(key == 123) ? k->beta_inc = 1 : (void)k->gopa;
	(key == 124) ? k->beta_dec = 1 : (void)k->gopa;
	(key == 125) ? k->alfa_inc = 1 : (void)k->gopa;
	(key == 126) ? k->alfa_dec = 1 : (void)k->gopa;
	return (0);
}

int		key_release(int key, t_key *k)
{
	(key == 33) ? k->z_re_u = 0 : (void)k->gopa;
	(key == 30) ? k->z_re_d = 0 : (void)k->gopa;
	(key == 15) ? k->r_shi = 0 : (void)k->gopa;
	(key == 5) ? k->g_shi= 0 : (void)k->gopa;
	(key == 11) ? k->b_shi= 0 : (void)k->gopa;
	(key == 13) ? k->y_shift_up = 0 : (void)k->gopa;
	(key == 0) ? k->x_shift_down = 0 : (void)k->gopa;
	(key == 1) ? k->y_shift_down = 0 : (void)k->gopa;
	(key == 2) ? k->x_shift_up = 0 : (void)k->gopa;
	(key == 24) ? k->zoom_in = 0 : (void)k->gopa;
	(key == 27) ? k->zoom_out = 0 : (void)k->gopa;
	(key == 53) ? k->esc = 0 : (void)k->gopa;
	(key == 123) ? k->beta_inc = 0 : (void)k->gopa;
	(key == 124) ? k->beta_dec = 0 : (void)k->gopa;
	(key == 125) ? k->alfa_inc = 0 : (void)k->gopa;
	(key == 126) ? k->alfa_dec = 0 : (void)k->gopa;
	return (0);
}

void	change_params(t_sav *all)
{
	(all->keys.z_re_u == 1) ? all->mult_z += 1 : (void)all->keys.gopa;
	(all->keys.z_re_d == 1) ? all->mult_z -= 1 : (void)all->keys.gopa;
	(all->keys.r_shi == 1) ? all->rgb_shift += 0x110000 : (void)all->keys.gopa;
	(all->keys.g_shi == 1) ? all->rgb_shift += 0x1100 : (void)all->keys.gopa;
	(all->keys.b_shi == 1) ? all->rgb_shift += 0x11 : (void)all->keys.gopa;
	(all->keys.y_shift_up == 1) ? all->y_shift -= 10 : (void)all->keys.gopa;
	(all->keys.y_shift_down == 1) ? all->y_shift += 10 : (void)all->keys.gopa;
	(all->keys.x_shift_up == 1) ? all->x_shift += 10 : (void)all->keys.gopa;
	(all->keys.x_shift_down == 1) ? all->x_shift -= 10 : (void)all->keys.gopa;
	(all->keys.esc == 1) ? exit(0) : (void)all->keys.gopa;
	(all->keys.zoom_in == 1) ? all->zoom *= 1.01 : (void)all->keys.gopa;
	(all->keys.zoom_out == 1) ? all->zoom /= 1.01 : (void)all->keys.gopa;
	(all->keys.beta_inc == 1) ? all->gama += 3 * RAD: (void)all->keys.gopa;
	(all->keys.beta_dec == 1) ? all->gama -= 3 * RAD: (void)all->keys.gopa;
	(all->keys.alfa_inc == 1) ? all->alfa += 3 * RAD: (void)all->keys.gopa;
	(all->keys.alfa_dec == 1) ? all->alfa -= 3 * RAD: (void)all->keys.gopa;
}

int		loop_hook(t_sav *all)
{
	change_params(all);
	mlx_destroy_image(all->mlx, all->img);
	all->img = mlx_new_image(all->mlx, all->win_size_x, all->win_size_y);
	ft_px_put(ft_px_rot(all));
	mlx_put_image_to_window(all->mlx, all->win, all->img, 0, 0);
	ft_put_info(all);
	ft_putstr("printing..\n");
	return (0);
}
