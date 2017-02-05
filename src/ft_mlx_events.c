/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_events.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 14:10:55 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/05 16:16:05 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	keys_init(t_key *key)
{
	key->esc = 0;
	key->alfa_inc = 0;
	key->alfa_dec = 0;
	key->beta_inc = 0;
	key->beta_dec = 0;
	key->gopa = 0;
}

void	ft_mlx_events(t_sav *all)
{
	keys_init(&(all->keys));
	mlx_hook(all->win, 2, 1, key_press, &(all->keys));
	mlx_hook(all->win, 3, 2, key_release, &(all->keys));
	mlx_loop_hook(all->mlx, loop_hook, all);	
	mlx_loop(all->mlx);
}
