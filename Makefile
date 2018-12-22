# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 12:43:34 by amoroziu          #+#    #+#              #
#    Updated: 2018/12/19 11:50:40 by amoroziu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECKER = checker

PUSH_SWAP = push_swap

LIB = libft/libftprintf.a

SRC_CHECKER =	checker.c \
				commands.c \
				execute_commands.c \
				get_commands.c \
				get_stack.c \
				delete_stack.c \
				is_sorted.c

SRC_PUSH_SWAP = commands.c \
				get_stack.c \
				sorter.c \
				is_sorted.c \
				insertion_sort.c \
				sort_in_a.c \
				move_to_top.c \
				return.c \
				arr_func.c \
				recursive_sort.c \
				find_index.c


FLAGC = -Wall -Werror -Wextra

OBJ_CHECKER = $(SRC_CHECKER:%.c=%.o)

OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:%.c=%.o)

all: $(LIB) $(CHECKER) $(PUSH_SWAP)

$(LIB):
	@make -C libft

$(CHECKER): $(SRC_CHECKER)
	@gcc $(FLAGC) -c $(SRC_CHECKER)
	@gcc $(FLAGC) $(OBJ_CHECKER) $(LIB) -o $(CHECKER)

$(PUSH_SWAP): $(SRC_PUSH_SWAP)
	@gcc $(FLAGC) -c $(SRC_PUSH_SWAP)
	@gcc $(FLAGC) $(OBJ_PUSH_SWAP) $(LIB) -o $(PUSH_SWAP)

clean:
	@make clean -C libft
	@rm -f $(OBJ_CHECKER) $(OBJ_PUSH_SWAP)

fclean: clean
	@make fclean -C libft
	@rm -f $(CHECKER) $(PUSH_SWAP)

re: fclean all
