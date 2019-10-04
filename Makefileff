# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: samymone <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/03 23:14:16 by samymone          #+#    #+#              #
#    Updated: 2019/10/03 23:14:18 by samymone         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker

MAKE = make
LIB = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror

SRC_CHECKER = ./src/ft_error.c ./src/ft_stack.c ./src/ft_validation.c ./src/px.c \
			          ./src/rrx.c ./src/rx.c ./src/sx.c ./src/is_sorted.c ./src/ft_checker.c


HEADER = ./includes/ft_push_swap.h
LIB = ./libft/libft.a

OBJ_CK = $(SRC_PUSH_SWAP:.c=.o)


all: $(CHECKER)

%.o: %.c
	    gcc $(FLAGS) -c -o $@ $< -g

$(CHECKER): $(LIB) $(OBJ_CK)
	    gcc $(FLAGS) -I $(HEADER) $(LIB) -o $(CHECKER) $(SRC_CHECKER) -g


$(LIB):
	    $(MAKE) -C ./libft/

clean:
	    $(MAKE) clean -C ./libft
		rm -f $(OBJ_CK)


fclean: clean
	    $(MAKE) fclean -C ./libft
		rm -f $(CHECKER)


re: fclean all
