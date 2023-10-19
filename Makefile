# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ylarhris <ylarhris@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/26 15:19:11 by yismaail          #+#    #+#              #
#    Updated: 2023/10/19 00:19:55 by ylarhris         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d
CC			=	cc
CFLAGS		=	-fsanitize=address -g #-Werror -Wextra -Wall
RM			=	rm -rf
SRCS		=	main.c src/parsing/init_game.c src/parsing/get_data.c src/parsing/exit.c src/parsing/get_map.c src/parsing/check_map.c \
				src/rendering/initializer.c src/rendering/render2dmap.c src/rendering/eventHandler.c ./src/raycasting/raycaster.c
OBJS		= ${SRCS:.c=.o}

all			:	$(NAME)

$(NAME)	: $(SRCS)
		make -C libft
		$(CC) $(CFLAGS) $(SRCS) -Lmlx -lmlx -framework OpenGL -framework AppKit libft/libft.a -o $(NAME) 
			
clean		:
			$(RM) $(OBJS)
			make clean -C libft

fclean		: clean
			$(RM) $(NAME)
			make fclean -C libft

re			: fclean all

.PHONY: all clean fclean re
