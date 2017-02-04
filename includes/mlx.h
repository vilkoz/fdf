/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 15:56:29 by vrybalko          #+#    #+#             */
/*   Updated: 2017/02/04 16:00:06 by vrybalko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_H
# define MLX_H

void			*mlx_init();
/*
**	needed before everything else.
**	return (void *)0 if failed
*/

/*
** Basic actions
*/

void			*mlx_new_window(void *mlx_ptr, int size_x, int size_y,
		char *title);
/*
**	retu		rn void *0 if failed
*/
int				mlx_clear_window(void *mlx_ptr, void *win_ptr);
int				mlx_pixel_put(void *mlx_ptr, void *win_ptr, int x, int y,
		int color);
/*
**	orig		in for x & y is top left corner of the window
**	y do		wn is positive
**	colo		r is 0x00RRGGBB
*/

/*
** Image		 stuff
*/

void			*mlx_new_image(void *mlx_ptr, int width, int height);
/*
**	retu		rn void *0 if failed
**	obso		lete : image2 data is stored using bit planes
**	void			*mlx_new_image2(void *mlx_ptr,int width,int height);
*/
char			*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
		int *size_line, int *endian);
/*
**	endian : 0 = sever X is little endian, 1 = big endian
**	for mlx_new_image2, 2nd arg of mlx_get_data_addr is number_of_planes
*/
int				mlx_put_image_to_window(void *mlx_ptr, void *win_ptr,
		void *img_ptr, int x, int y);
unsigned int	mlx_get_color_value(void *mlx_ptr, int color);

/*
** dealing with Events
*/

int				mlx_mouse_hook (void *win_ptr, int (*funct_ptr)(),
		void *param);
int				mlx_key_hook (void *win_ptr, int (*funct_ptr)(), void *param);
int				mlx_expose_hook (void *win_ptr, int (*funct_ptr)(),
		void *param);

int				mlx_loop_hook (void *mlx_ptr, int (*funct_ptr)(), void *param);
int				mlx_loop (void *mlx_ptr);

/*
**	hook funct are called as follow :
**	expose_hook(void *param);
**	key_hook(int keycode, void *param);
**	mouse_hook(int button, int x,int y, void *param);
**	loop_hook(void *param);
*/

int				mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y,
		int color, char *string);
void			*mlx_xpm_to_image(void *mlx_ptr, char **xpm_data,
				int *width, int *height);
void			*mlx_xpm_file_to_image(void *mlx_ptr, char *filename,
				int *width, int *height);
int				mlx_destroy_window(void *mlx_ptr, void *win_ptr);

int				mlx_destroy_image(void *mlx_ptr, void *img_ptr);

/*
**	generic hook system for all events, and minilibX functions that
**	  can be hooked. Some macro and defines from X11/X.h are needed here.
*/

int				mlx_hook(void *win_ptr, int x_event, int x_mask,
				int (*funct)(), void *param);

int				mlx_do_key_autorepeatoff(void *mlx_ptr);
int				mlx_do_key_autorepeaton(void *mlx_ptr);
int				mlx_do_sync(void *mlx_ptr);

#endif
