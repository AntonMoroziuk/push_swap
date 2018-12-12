/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertion_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 12:38:48 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/12 11:35:54 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_stack *a)
{
	int			idx;
	int			min_idx;
	int			min;
	t_number	*cur;

	idx = 0;
	cur = a->head;
	min = cur->nb;
	while (cur)
	{
		if (cur->nb < min)
		{
			min = cur->nb;
			min_idx = idx;
		}
		idx++;
		cur = cur->next;
	}
	return (min_idx);
}

void		min_sort(t_stack *a, t_stack *b)
{
	if (a->size == 0 || is_sorted(a))
		while (b->size)
		{
			ft_putendl("pa");
			push(b, a);
		}
	else
	{
		move_to_top(a, find_min(a));
		ft_putendl("pb");
		push(a, b);
		min_sort(a, b);
	}
}

void		medium_sort(t_stack *a)
{
	t_stack		b;

	b.size = 0;
	b.head = NULL;
	b.tail = NULL;
	min_sort(a, &b);
}
