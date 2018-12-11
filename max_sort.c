/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   max_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 12:31:49 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/08 12:41:22 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		find_max(t_stack *stack)
{
	t_number	*cur;
	t_number	*max;
	int			max_idx;
	int			cur_idx;

	cur = stack->head;
	max = stack->head;
	max_idx = 0;
	cur_idx = 0;
	while (cur)
	{
		if (cur->nb > max->nb)
		{
			max = cur;
			max_idx = cur_idx;
		}
		cur = cur->next;
		cur_idx++;
	}
	return (max_idx);
}

int				find_index(t_stack *stack, t_number *nb)
{
	int			i;
	t_number	*cur;

	i = 0;
	cur = stack->head;
	while (cur != nb)
	{
		cur = cur->next;
		i++;
	}
	return (i);
}

void			move_to_top(t_stack *a, int elem_idx)
{
	if (elem_idx == 0 || elem_idx >= a->size)
		return ;
	if (a->size - elem_idx > elem_idx)
	{
		while (elem_idx > 0)
		{
			rotate(a);
			ft_putendl("ra");
			elem_idx--;;
		}
	}
	else
	{
		while (elem_idx <= a->size - 1)
		{
			rrotate(a);
			ft_putendl("rra");
			elem_idx++;
		}
	}
}

static void		push_down(t_stack *a, int idx, int elem_idx)
{
	t_number	*temp;
	t_stack		b;

	b.size = 0;
	b.tail = NULL;
	b.head = NULL;
	if (idx == a->size - 1)
	{
		while (++elem_idx <= idx + 1)
		{
			ft_putendl("rra");
			rrotate(a);
		}
		return ;
	}
	move_to_top(a, elem_idx);
	ft_putendl("pb");
	push(a, &b);
	move_to_top(a, idx + 1);
	ft_putendl("pa");
	push(&b, a);
	temp = a->head;
	while (temp->nb < temp->next->nb)
		temp = temp->next;
	move_to_top(a, find_index(a, temp->next));
}

void			max_sort(t_stack *a)
{
	int			i;
	int			elem_idx;

	i = 0;
	while (++i < a->size)
	{
		elem_idx = find_max(a);
		if (i + elem_idx != a->size)
			push_down(a, a->size - i, elem_idx);
	}
}