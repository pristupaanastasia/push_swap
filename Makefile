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

OBJ_PS = $(patsubst %.c,%.o,$(SRC_PUSH_SWAP))

all: $(PUSH_SWAP)

%.o: %.c
	    gcc $(FLAGS) -c -o $@ $< -g

$(PUSH_SWAP): $(LIB)
	    gcc $(FLAGS) -I $(HEADER) $(LIB) -o $(PUSH_SWAP) $(SRC_PUSH_SWAP) -g

$(LIB):
	    $(MAKE) -C ./libft/



clean:
	    $(MAKE) clean -C ./libft
		rm -f $(SRC_PUSH_SWAP:.c=.o)

fclean: clean
	    $(MAKE) fclean -C ./libft
		rm -f $(PUSH_SWAP)

re: fclean all