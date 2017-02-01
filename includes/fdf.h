/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:49:01 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/01 13:09:11 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H
#define __FDF_H

# include "mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# define ALFA M_PI_4
# define BETA M_PI_4

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
t_sav	*ft_px_transform(t_sav *all);
void	ft_draw_line(t_sav *all, int x0, int y0, int x1, int y1, int rgb);
void	ft_connect_px(t_sav *all);

#endif
