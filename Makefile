# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mriley <mriley@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/04 18:35:51 by samymone          #+#    #+#              #
#    Updated: 2019/10/30 16:56:54 by mriley           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
CHECKER = checker
MAKE = make
LIB = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror

SRC_PUSH_SWAP = ./src/ft_error.c ./src/ft_stack.c ./src/ft_validation.c \
				./src/px.c ./src/rrx.c ./src/sx.c ./src/is_sorted.c \
			    ./src/sort_stacks.c ./src/sorting_algorythm.c ./src/rx.c \
			    ./src/ft_push_swap.c ./src/rotations.c ./src/extra_functions.c \
			    ./src/cleaner.c

SRC_CHECKER = ./src/ft_error.c ./src/ft_stack.c ./src/ft_validation.c ./src/px.c \
			          ./src/rrx.c ./src/rx.c ./src/sx.c ./src/is_sorted.c \
			          ./src/ft_checker.c ./src/cleaner.c
HEADER = ./includes/ft_push_swap.h
LIB = ./libft/libft.a
LIB_PRINTF = ./ft_printf/libftprintf.a

OBJ_PS = $(SRC_PUSH_SWAP:.c=.o)

OBJ_CK = $(SRC_CHECKER:.c=.o)

all: $(CHECKER) $(PUSH_SWAP)

%.o: %.c
	    gcc $(FLAGS) -c -o $@ $< -g

$(PUSH_SWAP): $(LIB) $(LIB_PRINTF) $(OBJ_PS)
	    gcc $(FLAGS) -I $(HEADER) $(LIB) $(LIB_PRINTF) -o $(PUSH_SWAP) $(SRC_PUSH_SWAP) -g

$(CHECKER): $(LIB)  $(LIB_PRINTF) $(OBJ_CK)
	    gcc $(FLAGS) -I $(HEADER)  $(LIB) $(LIB_PRINTF) -o $(CHECKER) $(SRC_CHECKER) -g

$(LIB):
	    $(MAKE) -C ./libft/
$(LIB_PRINTF):
		$(MAKE) -C ./ft_printf/

clean:
	    $(MAKE) clean -C ./libft
		$(MAKE) clean -C ./ft_printf
		rm -f $(OBJ_PS)
		rm -f $(OBJ_CK)

fclean: clean
	    $(MAKE) fclean -C ./libft
		$(MAKE) fclean -C ./ft_printf
		rm -f $(PUSH_SWAP)
		rm -f $(CHECKER)

re: fclean all
