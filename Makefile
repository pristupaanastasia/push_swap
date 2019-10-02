# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mriley <mriley@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/02 21:39:12 by mriley            #+#    #+#              #
#    Updated: 2019/10/02 21:50:11 by mriley           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker
PUSH_SWAP = push_swap
MAKE = make
LIB = ./libft/libft.a
FLAGS = -Wall -Wextra -Werror
SRC_PUSH_SWAP = ./src/ft_error.c ./src/ft_stack.c ./src/ft_validation.c \
				        ./src/px.c ./src/rrx.c ./src/sx.c ./src/is_sorted.c \
						        ./src/sorting_algorythm.c ./src/ft_push_swap.c ./src/rx.c \
								        ./src/extra_functions.c
SRC_CHECKER = ./src/ft_error.c ./src/ft_stack.c ./src/ft_validation.c ./src/px.c \
			          ./src/rrx.c ./src/rx.c ./src/sx.c ./src/is_sorted.c ./src/ft_checker.c
HEADER = ./includes/ft_push_swap.h
LIB = ./libft/libft.a

OBJ_PS = $(SRC_PUSH_SWAP:.c=.o)

OBJ_CK = $(SRC_CHECKER:.c=.o)
	

all: $(CHECKER) $(PUSH_SWAP)


$(CHECKER): $(LIB)
	    gcc $(FLAGS) -I $(HEADER)  $(LIB) -o $(CHECKER) $(SRC_CHECKER)
$(PUSH_SWAP): $(LIB)
	    gcc $(FLAGS) -I $(HEADER)  $(LIB) -o $(PUSH_SWAP) $(SRC_PUSH_SWAP)
$(LIB):
	    $(MAKE) -C ./libft/
%.o: %.c
	    gcc $(FLAGS) -I $(HEADER) -o $@ -c $<
clean:
	    $(MAKE) clean -C ./libft
		    rm -f ./src/*.o
fclean: clean
	    $(MAKE) fclean -C ./libft
		    rm -f $(CHECKER) $(PUSH_SWAP)
re: fclean all
