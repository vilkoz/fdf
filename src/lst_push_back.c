/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_push_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 20:31:11 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/06 16:59:40 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_lst	*lst_push_back(t_lst *head, t_lst *lst)
{
	t_lst	*tmp;

	if (!head)
		return (lst);
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = lst;
	return (head);
}
