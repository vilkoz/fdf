/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:24:40 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/04 15:16:17 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	z_mult(int ac, char **av)
{
	if (ac == 2)
		return (10);
	else
		return (ft_atoi(av[2]));
}

static int	expose_hook(void *all)
{
	ft_px_put(all);
	return (0);
}

static int	my_key_funct(int key, void *all)
{
	if (key == 53)
		exit(0);
	if (key >= 123 && key <= 126)
		ft_choose_angle(key, all);
	return (0);
}

int			main(int argc, char **argv)
{
	t_sav	*all;

	if (argc < 2)
	{
		ft_putstr("Usage: ./fdf <map file> [z_multiplier]\n");
		return (1);
	}
	if ((all = ft_read_file(z_mult(argc, argv), argv[1])) == NULL)
		return (1);
	mlx_expose_hook(all->win, expose_hook, (void *)ft_px_transform(all));
	mlx_key_hook(all->win, my_key_funct, (void *)all);
	mlx_loop(all->mlx);
	return (0);
}
