NAME = push_swap
NAME_C = checker
CC = gcc
C_FLAGS = -Wall -Wextra -Werror
SRCS = push_swap.c \
		check.c \
		functions.c \
		algorithm.c \

SRCS_C = checker.c \

OBJ =$(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@make -C ft_printf/
	@$(CC) $(C_FLAGS) $(OBJ) ./ft_printf/libftprintf.a ./libft/libft.a -o $(NAME)

%.o: %.c
	@$(CC) $(C_FLAGS) -c $< -o $@

fclean: clean
	@make fclean -C ft_printf/
	@make clean -C libft/
	@rm -rf $(NAME)

clean:
	@make clean -C ft_printf/
	@make clean -C libft/
	@rm -rf $(OBJ)

re: fclean all
