/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_px_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 12:17:24 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/02 20:47:58 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_iso(t_sav *all, int *x, int *y, int z)
{
	int		x1;
	int		y1;

	x1 = *x - (all->winSizeX / 2);
	y1 = *y - (all->winSizeY / 2);
	z = z * all->multZ;
	*x = x1 * cos(BETA) + (-y1 * sin(ALFA) + -z * cos(ALFA)) * sin(BETA)
		+ (all->winSizeX / 2);
	*y = y1 * cos(ALFA) + -z * cos(ALFA) + (all->winSizeY / 2);
}

t_sav			*ft_px_transform(t_sav *all)
{
	int		stepX;
	int		stepY;
	t_lst	*tmp;
	t_lst	*head;

	stepX = all->winSizeX / all->sizeX;
	stepY = all->winSizeY / all->sizeY;
	tmp = all->lst;
	head = tmp;
	while (tmp)
	{
		tmp->x *= stepX;
		tmp->y *= stepY;
		ft_iso(all, &(tmp->x), &(tmp->y), tmp->z);
		tmp = tmp->next;
	}
	all->lst = head;
	return (all);
}
