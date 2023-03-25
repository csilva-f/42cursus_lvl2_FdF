# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csilva-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 19:02:20 by csilva-f          #+#    #+#              #
#    Updated: 2023/03/25 09:25:35 by csilva-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = clang
CFLAGS = -Wall -Werror -Wextra
LFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11

SRCS = main.c valid_map.c error_handler.c map2.c map.c canvas.c center_scale.c center_scale2.c bresenham.c

SRCS_BONUS = main_bonus.c valid_map_bonus.c error_handler_bonus.c map2_bonus.c map_bonus.c canvas_bonus.c \
			center_scale_bonus.c center_scale2_bonus.c bresenham_bonus.c menu_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(MINILIBX)
		${CC} ${FLAGS} -lm ${OBJS} ${LFLAGS} ${LIBFT} ${MINILIBX} -o ${NAME}

$(LIBFT):
		${MAKE} -C ./libft

$(MINILIBX):
		${MAKE} -C ./milibx-linux

bonus:
		$(OBJS_BONUS) $(LIBFT) $(MINILIBX)
		${CC} ${FLAGS} -lm ${OBJS_BONUS} ${LFLAGS} ${LIBFT} ${MINILIBX} -o ${NAME}

clean:	
		$(MAKE) clean -C ./libft
		rm -rf ${OBJS} ${OBJS_BONUS}

fclean:	clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)

re:	fclean all
