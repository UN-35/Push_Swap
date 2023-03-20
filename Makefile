# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoelansa <yoelansa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/03 14:52:05 by yoelansa          #+#    #+#              #
#    Updated: 2023/03/20 13:06:49 by yoelansa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= push_swap

CFLAGS= -Wall -Wextra -Werror 
# -fsanitize=address

SRC= ft_atoi.c ft_isdigit.c ft_strdup.c ft_split.c ft_strjoin.c ft_strlen.c push_swap.c swap__push.c lst_utils.c 

OBJ= $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	cc $(OBJ) $(CFLAGS) -o $(NAME)

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all