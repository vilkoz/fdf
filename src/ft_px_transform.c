/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_px_transform.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 12:17:24 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/01 14:09:26 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_iso(int *x, int *y, int z)
{
	int		x1;
	int		y1;

	x1 = *x;
	y1 = *y;
	*x = x1 * cos(BETA) + (-y1 * sin(ALFA) + -z * cos(ALFA)) * sin(BETA);
	*y = y1 * cos(ALFA) + -z * cos(ALFA);
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
		ft_iso(&(tmp->x), &(tmp->y), tmp->z);
		tmp->x += (all->sizeX / 3) * stepX;
		tmp = tmp->next;
	}
	all->lst = head;
	return (all);
}
