# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: prastoin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/07 11:13:09 by prastoin          #+#    #+#              #
#    Updated: 2019/05/23 14:05:27 by fbecerri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bc

include src.mk

INC = includes

OBJ = $(SRCS:.c=.o)

LIB = num.a

FLAG = -Wall

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAG) $(LIB) -I$(INC) $(OBJ) -o $(NAME)

%.o: %.c
		gcc $(FLAG) -I$(INC) -o $@ -c $<

clean:
			rm -rf $(OBJ)

fclean: clean
			rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean re all
