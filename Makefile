NAME = push_swap

SRC = 	push_swap.c \
		rotate_a.c \
		smallStack.c \
		bigStack.c \
		doubly_lst.c \
		put_to_a.c \
		errors.c \
		ft_free.c \
		operations.c \
		index.c \
		push.c \
		get_min_and_max.c

INCLUDE = -I ./includes
OBJ = $(SRC:%.c=%.o)

LIBFT_DIR = ./libft

LIBFT = $(LIBFT_DIR)/libft.a

CFLAGS = -Wall -Werror -Wextra
DEBUG =  #-fsanitize=address -g 

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	gcc -g $(OBJ) $(LIBFT) $(DEBUG) -o $(NAME) 

%.o: %.c
	gcc -c -g $(INCLUDE) $(CFLAGS) $(DEBUG) $< -o $@

$(LIBFT): 
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) fclean -C $(LIBFT_DIR)
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all
