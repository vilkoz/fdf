/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect_px.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:00:58 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/06 14:23:52 by vrybalko         ###   ########.fr       */
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
		if ((vnext = get_n_lst_el(tmp, all->size_x - 1)) != NULL)
			ft_draw_line(all, tmp, vnext);
		tmp = tmp->next;
	}
}

static void		connect_diag(t_sav *all)
{
	t_lst	*tmp;
	t_lst	*vnext;
	int		i;

	i = 1;
	tmp = all->lst;
	while (tmp)
	{
		if (i == all->size_x - 1)
			i = 0;
		else
		{
			if ((vnext = get_n_lst_el(tmp, all->size_x)) != NULL)
				ft_draw_line(all, tmp, vnext);
		}
		tmp = tmp->next;
		i++;
	}
}

static void		connect_hor(t_sav *all)
{
	t_lst	*tmp;
	int		i;

	i = 1;
	tmp = all->lst;
	while (tmp->next)
	{
		if (i == all->size_x - 1)
			i = 0;
		else
			ft_draw_line(all, tmp, tmp->next);
		tmp = tmp->next;
		i++;
	}
}

void			ft_connect_px(t_sav *all)
{
	if (all->size_x < 300)
		connect_vertical(all);
	if (all->size_y < 150 && all->size_x < 150)
		connect_diag(all);
	connect_hor(all);
}
