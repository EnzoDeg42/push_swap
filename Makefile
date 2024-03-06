# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edegraev <edegraev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/08 15:24:43 by edegraev          #+#    #+#              #
#    Updated: 2024/03/01 14:45:13 by edegraev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
SRC = src/is_sorted.c src/is_valid_number_format.c src/action_both.c src/algo_move_and_cost.c src/ft_split.c src/get_stack.c src/action.c src/algo_move_low_cost_action.c src/ft_strfind.c src/move_low_cost.c src/action_do.c src/algo_short.c src/ft_strlen.c src/push_swap.c src/add_to_stack.c src/display.c src/ft_swap.c src/quit.c src/algo.c src/ft_atol.c src/get.c src/push_swap_extra.c
SRCB = srcb/is_sorted.c srcb/is_valid_number_format.c srcb/get_next_line.c srcb/get_next_line_utils.c srcb/action_both.c srcb/algo_move_and_cost.c srcb/ft_split.c srcb/get_stack.c srcb/action.c srcb/algo_move_low_cost_action.c srcb/ft_strfind.c srcb/move_low_cost.c srcb/action_do.c srcb/algo_short.c srcb/ft_strlen.c srcb/push_swap.c srcb/add_to_stack.c srcb/display.c srcb/ft_swap.c srcb/quit.c srcb/algo.c srcb/ft_atol.c srcb/get.c srcb/push_swap_extra.c
OBJ = $(SRC:.c=.o)
OBJS = $(SRCB:.c=.o)
INCLUDES = -Iincludes

all: $(NAME) $(NAME_BONUS)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ)

$(NAME_BONUS): $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME_BONUS) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

bonus: $(NAME_BONUS)

norme:
	norminette src srcb includes

clean:
	rm -f src/*.o
	rm -f srcb/*.o

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all
