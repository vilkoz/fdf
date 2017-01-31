/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 17:01:30 by vrybalko          #+#    #+#             */
/*   Updated: 2017/01/31 21:51:43 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_sav	*ft_read_file(char *s)
{
	int		fd;
	int		i;
	char	*line;
	t_sav	*all;

	i = 1;
	if ((fd = open(s, O_RDONLY)) < 0)
	{
		ft_putstr("file not found\n");
		return (NULL);
	}
	all = ft_sav_init(s);
	while (get_next_line(fd, &line))
	{
		all->lst = lst_push_back(all->lst, lst_push_line(all, line, i));
		free(line);
		line = NULL;
		i++;
	}
	all->sizeY = (all->sizeY == -1) ? i : -1;
	return (all);
}
