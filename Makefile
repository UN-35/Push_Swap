# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 14:52:05 by yoelansa          #+#    #+#              #
#    Updated: 2023/03/24 14:41:06 by yoelansa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

CFLAGS= -Wall -Wextra -Werror 
# -fsanitize=address

SRC= libft/ft_atoi.c libft/ft_isdigit.c libft/ft_strdup.c \
 	libft/ft_split.c libft/ft_strjoin.c libft/ft_strlen.c \
 	push_swap.c utils/swap__push.c utils/lst_utils.c utils/rotation.c \
	utils/parse_args.c utils/utils.c

OBJ= $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	cc $(OBJ) $(CFLAGS) -o $(NAME)

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all