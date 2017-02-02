/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:49:01 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/02 20:00:38 by vrybalko         ###   ########.fr       */
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
	int				multZ;
	t_lst			*lst;
}					t_sav;

typedef struct		s_lin
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				d;
	int				d1;
	int				d2;
	int				drgb;
	int				error;
	int				error2;
	t_lst			*p1;
	t_lst			*p2;
}					t_lin;

t_sav	*ft_read_file(int z, char *s);
t_sav	*ft_sav_init(int z, char *title);
t_lst	*lst_push_line(t_sav *all, char *line, int y);
t_lst	*lst_push_back(t_lst *head, t_lst *lst);
void	ft_px_put(t_sav *all);
t_sav	*ft_px_transform(t_sav *all);
void	ft_draw_line(t_sav *all, t_lst *p1, t_lst *p2);
void	ft_connect_px(t_sav *all);
void	drawLine(t_sav *all, t_lst *p1, t_lst *p2);


#endif
