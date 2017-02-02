/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:48:32 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/02 20:46:30 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_lst	*lst_new(int x, int y, int z, int rgb)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	new->x = x;
	new->y = y;
	new->z = z;
	new->rgb = rgb;
	new->next = NULL;
	return (new);
}

t_lst			*lst_push_line(t_sav *all, char *line, int y)
{
	char	**tmp;
	int		x;
	t_lst	*lst;

	x = 1;
	tmp = ft_strsplit(line, 32);
	lst = NULL;
	while (tmp[x - 1] != NULL)
	{
		lst = lst_push_back(lst, lst_new(x, y, ft_atoi(tmp[x - 1]),
				(ft_strchr(tmp[x - 1], 'x') != NULL) ?
				ft_atoi_base(ft_strchr(tmp[x - 1], 'x') + 1, 16) : 0x00FFFFFF));
		x++;
	}
	if (all->sizeX == -1)
		all->sizeX = x;
	return (lst);
}
