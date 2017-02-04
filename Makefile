# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vrybalko <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/23 14:08:11 by vrybalko          #+#    #+#              #
#    Updated: 2017/02/04 21:28:16 by vrybalko         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

IDIR = includes/

VPATH = src:includes

FLAGS = -Wall -Wextra -Werror -I$(IDIR) -g

FLAGS_MLX = -lmlx -framework OpenGl -framework AppKit

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
	   ft_choose_angle.c		\
	   ft_img_pixel_put.c

BINS = $(SRCS:.c=.o)

all: $(NAME)

makelib:
	make -C libft/

$(NAME): $(BINS)
	gcc -o $(NAME) $(BINS) $(FLAGS) $(FLAGS_MLX) $(LIB)

%.o: %.c
	gcc $(FLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(BINS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
