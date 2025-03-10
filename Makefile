NAME = push_swap
NAME_C = checker
CC = gcc
C_FLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c \
		check.c \
		functions.c \
		functions_two.c \
		functions_three.c \
		algorithm.c \
		cost_algorithm.c \
		push_algorithm.c \
		stck_a_func.c \
		stck_b_func.c \
		ft_new_atoi.c

SRCS_C = checker.c \

OBJ =$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) $(C_FLAGS) $(OBJ) libft/libft.a -o $(NAME)

%.o: %.c
	@$(CC) $(C_FLAGS) -c $< -o $@

fclean: clean
	@make fclean -C libft/
	@rm -rf $(NAME)

clean:
	@make clean -C libft/
	@rm -rf $(OBJ)

re: fclean all
