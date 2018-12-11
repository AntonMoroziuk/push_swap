# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 12:43:34 by amoroziu          #+#    #+#              #
#    Updated: 2018/12/06 12:43:36 by amoroziu         ###   ########.fr        #
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
				max_sort.c \
				quick_sort.c \
				is_sorted.c \
				swap_at_indexes.c \
				work_with_pivot.c \
				insertion_sort.c

FLAGC = -Wall -Werror -Wextra

OBJ_CHECKER = $(SRC_CHECKER:%.c=%.o)

OBJ_PUSH_SWAP = $(SRC_PUSH_SWAP:%.c=%.o)

all: $(CHECKER) $(PUSH_SWAP)

$(CHECKER): $(SRC_CHECKER)
	@gcc $(FLAGC) -c $(SRC_CHECKER)
	@gcc $(FLAGC) $(OBJ_CHECKER) $(LIB) -o $(CHECKER)

$(PUSH_SWAP): $(SRC_PUSH_SWAP)
	@gcc $(FLAGC) -c $(SRC_PUSH_SWAP)
	@gcc $(FLAGC) $(OBJ_PUSH_SWAP) $(LIB) -o $(PUSH_SWAP)

clean:
	@rm -f $(OBJ_CHECKER) $(OBJ_PUSH_SWAP)

fclean: clean
	@rm -f $(CHECKER) $(PUSH_SWAP)

re: fclean all