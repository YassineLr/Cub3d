# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/26 15:19:11 by yismaail          #+#    #+#              #
#    Updated: 2023/10/04 13:29:20 by ylarhris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d
CC			=	cc
CFLAGS		=	-Imlx_linux #-Werror -Wextra -Wall  #-fsanitize=address -g
RM			=	rm -rf
SRCS		=	main.c src/parsing/init_game.c src/parsing/get_data.c src/parsing/exit.c src/parsing/get_map.c src/parsing/check_map.c \
				src/rendering/initializer.c src/rendering/render2dmap.c src/rendering/eventHandler.c ./src/raycasting/raycaster.c
OBJS		= ${SRCS:.c=.o}

all			:	$(NAME)

$(NAME)	: $(SRCS)
		make -C libft
		$(CC) $(CFLAGS) $(SRCS)  -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz libft/libft.a -o $(NAME) -lm
			
clean		:
			$(RM) $(OBJS)
			make clean -C libft

fclean		: clean
			$(RM) $(NAME)
			make fclean -C libft

re			: fclean all

.PHONY: all clean fclean re
