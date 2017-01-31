/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:24:40 by vrybalko          #+#    #+#             */
/*   Updated: 2017/01/31 21:25:08 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		main(int argc, char **argv)
{
	t_sav	*all;

	if (argc != 2)
	{
		ft_putstr("Usage: ./fdf <map file>\n");
		return (1);
	}
	if ((all = ft_read_file(argv[1])) == NULL)
		return (1);
	ft_px_put(all);
	return (0);	
}
