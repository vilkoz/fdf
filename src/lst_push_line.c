/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:48:32 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/04 15:15:57 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_lst	*lst_new(int x, int y, int z, int rgb)
{
	t_lst	*new;

	new = (t_lst *)malloc(sizeof(t_lst));
	new->x = x;
	new->x1 = x;
	new->y = y;
	new->y1 = y;
	new->z = z;
	new->z1 = z;
	new->rgb = rgb;
	new->next = NULL;
	return (new);
}

static void		*ft_puterror(int num)
{
	if (num == 0)
	{
		ft_putstr("map error: lines should have same length\n");
		exit(1);
	}
	return (NULL);
}

t_lst			*lst_push_line(t_sav *all, char *line, int y)
{
	char	**tmp;
	int		x;
	t_lst	*lst;

	x = 1;
	tmp = ft_strsplit(line, 32);
	lst = NULL;
	while (tmp[x - 1] != NULL &&
			x < (all->size_x == -1 ? 0xFFFFFF : all->size_x))
	{
		lst = lst_push_back(lst, lst_new(x, y, ft_atoi(tmp[x - 1]),
				(ft_strchr(tmp[x - 1], 'x') != NULL) ?
				ft_atoi_base(ft_strchr(tmp[x - 1], 'x') + 1, 16) : 0x00FFFFFF));
		x++;
	}
	if (all->size_x == -1)
		all->size_x = x;
	else if (x < all->size_x)
		return (ft_puterror(0));
	return (lst);
}
