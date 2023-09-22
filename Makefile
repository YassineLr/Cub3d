# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yismaail <yismaail@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/26 15:19:11 by yismaail          #+#    #+#              #
#    Updated: 2023/09/22 08:22:56 by yismaail         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	cub3d
CC			=	cc
CFLAGS		=	-Werror -Wextra -Wall  #-fsanitize=address -g
RM			=	rm -rf
SRCS		=	main.c src/init_game.c src/get_data.c src/exit.c src/get_map.c src/check_map.c
				
OBJS		= ${SRCS:.c=.o}

all			:	$(NAME)

$(NAME)	: $(SRCS)
		make -C libft
		$(CC) $(CFLAGS) $(SRCS) libft/libft.a -o $(NAME) -lm
			
clean		:
			$(RM) $(OBJS)
			make clean -C libft

fclean		: clean
			$(RM) $(NAME)
			make fclean -C libft

re			: fclean all

.PHONY: all clean fclean re
