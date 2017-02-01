/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_connect_px.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 13:00:58 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/01 14:08:09 by vrybalko         ###   ########.fr       */
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
			ft_draw_line(all, tmp->x, tmp->y, vnext->x,
				vnext->y, tmp->rgb);
		tmp = tmp->next;
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
		if (i == all->sizeX - 1)
			i = 0;
		else
			ft_draw_line(all, tmp->x, tmp->y, tmp->next->x,
					tmp->next->y, tmp->rgb);
		tmp = tmp->next;
		i++;
	}
}

void			ft_connect_px(t_sav *all)
{
	connect_vertical(all);
	connect_hor(all);
}
