# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: csilva-f <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/07 19:02:20 by csilva-f          #+#    #+#              #
#    Updated: 2023/01/29 10:41:44 by csilva-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

CC = clang
CFLAGS = -g -Wall -Werror -Wextra

SRCS =

OBJS = $(SRCS:.c=.o)

LIBFT = libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		${CC} ${FLAGS} ${OBJS} ${LIBFT} -o ${NAME}


$(LIBFT):
		${MAKE} -C ./libft

clean:	
		$(MAKE) clean -C ./libft
		rm -rf ${OBJS}

fclean:	clean
		$(MAKE) fclean -C ./libft
		rm -rf $(NAME)

re:	fclean all bonus
