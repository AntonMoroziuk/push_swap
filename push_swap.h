/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:14:26 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/19 11:57:21 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct	s_number
{
	int				nb;
	struct s_number	*next;
}				t_number;

typedef struct	s_stack
{
	t_number		*head;
	t_number		*tail;
	int				size;
}				t_stack;

typedef struct	s_group
{
	t_number		*start;
	t_number		*end;
}				t_group;

int				get_stack(int argc, char **argv, t_stack *stack);
int				get_commands(char ***commands);
int				execute_commands(char **commands, t_stack *a);
int				find_index(t_stack *stack, t_number *nb);
int				is_sorted(t_stack *stack);
int				index_value(int idx, t_stack *stack);
int				find_median(int *table, int size);
int				*to_arr(t_stack *stack, int size);
void			recursive_sort(t_stack *a);
void			medium_sort(t_stack *a);
void			easy_sort(t_stack *a);
void			easy_return(t_stack *a, t_stack *b, int b_size);
void			move_to_top(t_stack *a, int elem_idx);
void			rotate(t_stack *stack);
void			swap(t_stack *stack);
void			push(t_stack *from, t_stack *to);
void			sort_in_a(t_stack *a, t_stack *b, int size);
void			return_to_a(t_stack *a, t_stack *b, int size);
void			rrotate(t_stack *stack);
void			delete_stack(t_stack *stack);

#endif
