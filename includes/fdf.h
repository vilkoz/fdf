/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:49:01 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/06 13:40:26 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H
# define __FDF_H

# include "mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# define ALFA M_PI_4
# define BETA M_PI_4
# define RAD (M_PI / 360)

typedef struct		s_lst
{
	int				x;
	int				x1;
	int				y;
	int				y1;
	int				z;
	int				z1;
	int				rgb;
	struct s_lst	*next;
}					t_lst;

typedef	struct		s_key
{
	int				esc;
	int				alfa_inc;
	int				alfa_dec;
	int				beta_inc;
	int				beta_dec;
	int				gopa;
	int				zoom_in;
	int				zoom_out;
	int				y_shift_up;
	int				x_shift_up;
	int				y_shift_down;
	int				x_shift_down;
	int				r_shi;
	int				g_shi;
	int				b_shi;
	int				z_re_u;
	int				z_re_d;
	int				iso;
}					t_key;

typedef	struct		s_sav
{
	void			*mlx;
	void			*win;
	void			*img;
	int				win_size_x;
	int				win_size_y;
	int				size_x;
	int				size_y;
	int				mult_z;
	t_key			keys;
	double			alfa;
	double			beta;
	double			gama;
	double			s_alfa;
	double			s_beta;
	double			s_gama;
	double			zoom;
	int				x_shift;
	int				y_shift;
	int				rgb_shift;
	int				txt_shift;
	t_lst			*lst;
}					t_sav;

typedef struct		s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct		s_lin
{
	int				dx;
	int				dy;
	int				sx;
	int				sy;
	int				d;
	int				d1;
	int				d2;
	t_rgb			drgb;
	int				error;
	int				error2;
	t_lst			*p1;
	t_lst			*p2;
}					t_lin;

t_sav				*ft_read_file(int z, char *s);
t_sav				*ft_sav_init(int z, char *title);
t_lst				*lst_push_line(t_sav *all, char *line, int y);
t_lst				*lst_push_back(t_lst *head, t_lst *lst);
void				ft_px_put(t_sav *all);
t_sav				*ft_px_transform(t_sav *all);
void				ft_draw_line(t_sav *all, t_lst *p1, t_lst *p2);
void				ft_connect_px(t_sav *all);
void				ft_draw_line(t_sav *all, t_lst *p1, t_lst *p2);
t_sav				*ft_px_rot(t_sav *all);
void				ft_win_clear(t_sav *all);
void				ft_choose_angle(int	key, void *all);
void				ft_img_pixel_put(t_sav *all, int x, int y, int rgb);
int					key_press(int key, t_key *k);
int					key_release(int key, t_key *k);
int					loop_hook(t_sav *all);
void				ft_mlx_events(t_sav *all);
void				ft_put_info(t_sav *all);
void				make_iso(t_sav *all);

#endif
