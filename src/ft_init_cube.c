/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_cube.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/06 14:50:54 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/06 17:04:13 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_lst	*lst_helper(t_sav *all, t_lst *lst)
{
	lst = lst_push_back(lst, lst_new(2, 1, ((all->win_size_x / 2)), 0xff));
	lst = lst_push_back(lst, lst_new(2, 1, ((all->win_size_x / 2)), 0xff));
	lst = lst_push_back(lst, lst_new(2, 2, ((all->win_size_x / 2)), 0xff));
	lst = lst_push_back(lst, lst_new(2, 2, ((all->win_size_x / 2)), 0xff));
	lst = lst_push_back(lst, lst_new(1, 2, ((all->win_size_x / 2)), 0xff));
	lst = lst_push_back(lst, lst_new(1, 2, ((all->win_size_x / 2)), 0xff));
	lst = lst_push_back(lst, lst_new(1, 1, ((all->win_size_x / 2)), 0xff));
	lst = lst_push_back(lst, lst_new(1, 1, ((all->win_size_x / 2)), 0xff));
	lst = lst_push_back(lst, lst_new(1, 1, 0, 0xff));
	lst = lst_push_back(lst, lst_new(1, 2, ((all->win_size_x / 2)), 0xff));
	lst = lst_push_back(lst, lst_new(1, 2, 0, 0xff));
	lst = lst_push_back(lst, lst_new(2, 2, ((all->win_size_x / 2)), 0xff));
	lst = lst_push_back(lst, lst_new(2, 2, 0, 0xff));
	lst = lst_push_back(lst, lst_new(2, 1, ((all->win_size_x / 2)), 0xff));
	lst = lst_push_back(lst, lst_new(2, 1, 0, 0xff));
	return (lst);
}

t_sav	*ft_init_cube(t_sav *all)
{
	t_lst *lst;

	lst = NULL;
	lst = lst_new(1, 1, 0, 0xff);
	lst = lst_push_back(lst, lst_new(2, 1, 0, 0xff));
	lst = lst_push_back(lst, lst_new(2, 1, 0, 0xff));
	lst = lst_push_back(lst, lst_new(2, 2, 0, 0xff));
	lst = lst_push_back(lst, lst_new(2, 2, 0, 0xff));
	lst = lst_push_back(lst, lst_new(1, 2, 0, 0xff));
	lst = lst_push_back(lst, lst_new(1, 2, 0, 0xff));
	lst = lst_push_back(lst, lst_new(1, 1, 0, 0xff));
	lst = lst_push_back(lst, lst_new(1, 1, ((all->win_size_x / 2)), 0xff));
	lst = lst_helper(all, lst);
	all->size_x = 2;
	all->size_y = 2;
	all->mult_z = 1;
	all->lst = lst;
	return (all);
}
