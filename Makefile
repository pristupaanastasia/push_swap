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

MAKE = make
LIB = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror

SRC_PUSH_SWAP = ./src/ft_error.c ./src/ft_stack.c ./src/ft_validation.c \
				./src/px.c ./src/rrx.c ./src/sx.c ./src/is_sorted.c \
			    ./src/sort_stacks.c ./src/sorting_algorythm.c ./src/ft_push_swap.c ./src/rx.c \
				./src/rotations.c ./src/extra_functions.c


HEADER = ./includes/ft_push_swap.h
LIB = ./libft/libft.a

OBJ_PS = $(SRC_PUSH_SWAP:.c=.o)


all: $(PUSH_SWAP)

%.o: %.c
	    gcc $(FLAGS) -c -o $@ $< -g

$(PUSH_SWAP): $(LIB) $(OBJ_PS)
	    gcc $(FLAGS) -I $(HEADER) $(LIB) -o $(PUSH_SWAP) $(SRC_PUSH_SWAP) -g


$(LIB):
	    $(MAKE) -C ./libft/

clean:
	    $(MAKE) clean -C ./libft
		rm -f $(OBJ_PS)


fclean: clean
	    $(MAKE) fclean -C ./libft
		rm -f $(PUSH_SWAP)


re: fclean all
