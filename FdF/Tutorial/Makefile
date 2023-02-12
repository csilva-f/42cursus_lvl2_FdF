# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csilva-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 19:02:20 by csilva-f          #+#    #+#              #
#    Updated: 2023/02/11 16:55:49 by csilva-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = tutorial

CC = clang
CFLAGS = -g -Wall -Werror -Wextra
LFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11

SRCS = main.c

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
		${CC} ${FLAGS} -lm ${OBJS} ${LFLAGS} ${LIBFT} ${MINILIBX} -o ${NAME}

$(LIBFT):
		${MAKE} -C ./libft
	
$(MINILIBX):
		${MAKE} -C ./minilibx-linux

clean:	
		$(MAKE) clean -C ./libft
		rm -rf ${OBJS}

fclean:	clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)

re:	fclean all bonus
