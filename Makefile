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

PUSH_SWAP = push_swap
CHECKER = checker
MAKE = make
LIB = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror

SRC_PUSH_SWAP = ./src/ft_error.c ./src/ft_stack.c ./src/ft_validation.c \
				./src/px.c ./src/rrx.c ./src/sx.c ./src/is_sorted.c \
			    ./src/sort_stacks.c ./src/sorting_algorythm.c ./src/ft_push_swap.c ./src/rx.c \
				./src/rotations.c ./src/extra_functions.c

SRC_CHECKER = ./src/ft_error.c ./src/ft_stack.c ./src/ft_validation.c ./src/px.c \
			          ./src/rrx.c ./src/rx.c ./src/sx.c ./src/is_sorted.c ./src/ft_checker.c
HEADER = ./includes/ft_push_swap.h
LIB = ./libft/libft.a

OBJ_PS = $(patsubst %.c,%.o,$(SRC_PUSH_SWAP))

OBJ_CK = $(SRC_CHECKER:.c=.o)

all: $(CHECKER) $(PUSH_SWAP)

%.o: %.c
	    gcc $(FLAGS) -c -o $@ $< -g

$(PUSH_SWAP): $(LIB)
	    gcc $(FLAGS) -I $(HEADER) $(LIB) -o $(PUSH_SWAP) $(SRC_PUSH_SWAP) -g

$(CHECKER): $(LIB)
	    gcc $(FLAGS) -I $(HEADER)  $(LIB) -o $(CHECKER) $(SRC_CHECKER)

$(LIB):
	    $(MAKE) -C ./libft/

clean:
	    $(MAKE) clean -C ./libft
		rm -f $(SRC_PUSH_SWAP:.c=.o)
		rm -f $(SRC_CHECKER:.c=.o)

fclean: clean
	    $(MAKE) fclean -C ./libft
		rm -f $(PUSH_SWAP)
		rm -f $(SRC_CHECKER)

re: fclean all
