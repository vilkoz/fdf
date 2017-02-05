# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/23 14:08:11 by vrybalko          #+#    #+#              #
#    Updated: 2017/02/05 17:40:42 by vrybalko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

IDIR = includes/

VPATH = src:includes

FLAGS = -Wall -Wextra -Werror -I$(IDIR) -g

FLAGS_MLX = -lmlx -framework OpenGl -framework AppKit

FLAGS_X11 = -lmlx -lXext -lX11 -lm

LIB = libft/libft.a

SRCS = main.c					\
	   ft_read_file.c			\
	   ft_sav_init.c			\
	   lst_push_back.c			\
	   lst_push_line.c			\
	   ft_px_put.c				\
	   ft_px_transform.c		\
	   ft_draw_line.c			\
	   ft_connect_px.c			\
	   ft_px_rot.c				\
	   ft_win_clear.c			\
	   ft_img_pixel_put.c		\
	   ft_mlx_events.c			\
	   ft_hooks.c				\
	   ft_put_info.c
	   #ft_choose_angle.c		\

BINS = $(SRCS:.c=.o)

all: $(NAME)

makelib:
	make -C libft/

libclean:
	make -C libft/ clean

libfclean:
	make -C libft/ fclean

$(NAME): $(BINS) makelib
	gcc -o $(NAME) $(BINS) $(FLAGS) $(FLAGS_MLX) $(LIB)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean: libclean
	/bin/rm -f $(BINS)

fclean: libfclean clean
	/bin/rm -f $(NAME)

re: fclean all
