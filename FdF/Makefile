# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csilva-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 19:02:20 by csilva-f          #+#    #+#              #
#    Updated: 2023/02/12 21:15:13 by csilva-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = clang
CFLAGS = -g -Wall -Werror -Wextra
LFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11

SRCS = main.c map2.c map.c test.c canvas.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
		${CC} ${FLAGS} -lm ${OBJS} ${LFLAGS} ${LIBFT} ${MINILIBX} -o ${NAME}

$(LIBFT):
		${MAKE} -C ./libft

$(MINILIBX):
		${MAKE} -C ./milibx-linux

clean:	
		$(MAKE) clean -C ./libft
		rm -rf ${OBJS}

fclean:	clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)

re:	fclean all bonus
