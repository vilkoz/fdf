/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:24:40 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/02 17:29:04 by vrybalko         ###   ########.fr       */
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
	ft_px_put(all);
	return (0);	
}
