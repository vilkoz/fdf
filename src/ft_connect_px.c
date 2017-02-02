/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect_px.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:00:58 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/02 20:26:15 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_lst	*get_n_lst_el(t_lst *lst, int n)
{
	t_lst	*tmp;
	int		i;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		if (i >= n)
			return (tmp);
		tmp = tmp->next;
		i++;
	}
	return (NULL);
}

static void		connect_vertical(t_sav *all)
{
	t_lst	*tmp;
	t_lst	*vnext;

	tmp = all->lst;
	while (tmp)
	{
		if ((vnext = get_n_lst_el(tmp, all->sizeX - 1)) != NULL)
			drawLine(all, tmp, vnext);
		tmp = tmp->next;
	}
}
/*
static void		connect_diag(t_sav *all)
{
	t_lst	*tmp;
	t_lst	*vnext;
	int		i;

	i = 1;
	tmp = all->lst;
	while (tmp)
	{
		if (i == all->sizeX - 1)
			i = 0;
		else
			if ((vnext = get_n_lst_el(tmp, all->sizeX)) != NULL)
				drawLine(all, tmp, vnext);
		tmp = tmp->next;
		i++;
	}
}
*/
static void		connect_hor(t_sav *all)
{
	t_lst	*tmp;
	int		i;

	i = 1;
	tmp = all->lst;
	while (tmp->next)
	{
		if (i == all->sizeX - 1)
			i = 0;
		else
			drawLine(all, tmp, tmp->next);
		tmp = tmp->next;
		i++;
	}
}

void			ft_connect_px(t_sav *all)
{
	connect_vertical(all);
	//connect_diag(all);
	connect_hor(all);
}
