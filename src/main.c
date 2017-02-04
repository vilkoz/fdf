/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:24:40 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/04 21:28:09 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static int	z_mult(int ac, char **av)
{
	if (ac == 2)
		return (10);
	else
		return (ft_atoi(av[2]));
}

static int	expose_hook(void *all)
{
	((t_sav *)all)->img = mlx_new_image(((t_sav *)all)->mlx,
		((t_sav *)all)->win_size_x, ((t_sav *)all)->win_size_y);
	printf("img = %p\n", ((t_sav *)all)->img);
	printf("char = %lu, int = %lu\n", sizeof('a'), sizeof(1));
	ft_px_put((t_sav *)all);
	mlx_put_image_to_window(((t_sav *)all)->mlx, ((t_sav *)all)->win,
		((t_sav *)all)->img, 1, 1);
	return (0);
}

static int	my_key_funct(int key, void *all)
{
	printf("key = %d\n", key);
	((t_sav *)all)->key = key;
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
