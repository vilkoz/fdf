/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:49:01 by vrybalko          #+#    #+#             */
/*   Updated: 2017/01/31 21:20:53 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H
#define __FDF_H

# include "mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>

typedef struct		s_lst
{
	int				x;
	int				y;
	int				z;
	int				rgb;
	struct s_lst 	*next;	
}					t_lst;

typedef	struct		s_sav
{
	void			*mlx;
	void			*win;
	int				i;
	int				j;
	int				k;
	int				winSizeX;
	int				winSizeY;
	int				sizeX;
	int				sizeY;
	t_lst			*lst;
}					t_sav;

t_sav	*ft_read_file(char *s);
t_sav	*ft_sav_init(char *title);
t_lst	*lst_push_line(t_sav *all, char *line, int y);
t_lst	*lst_push_back(t_lst *head, t_lst *lst);
void	ft_px_put(t_sav *all);

#endif
