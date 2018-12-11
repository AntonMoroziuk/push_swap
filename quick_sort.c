/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:46:32 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/09 14:46:33 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		return_to_a(t_stack *a, t_stack *b)
{
	if (b->size > 1)
	{
		ft_putendl("rrb");
		rrotate(b);
	}
	while (b->size)
	{
		ft_putendl("pa");
		push(b, a);
	}
}

static t_number	*elem_with_index(t_stack *stack, int idx)
{
	t_number	*cur;

	cur = stack->head;
	while (idx)
	{
		cur = cur->next;
		idx--;
	}
	return (cur);
}

static void		swap_elements(t_stack *a, t_number *i)
{
	int		idx;

	idx = find_index(a, i);
	move_to_top(a, idx);
	swap(a);
	ft_putendl("sa");
}

static void		sort(t_stack *a, t_stack *b, t_number *start, t_number *end)
{
	t_number	*old_head;
	t_group		new;
	t_group		old;

	ft_printf("%d %d\n", start->nb, end->nb);
	new.start = NULL;
	new.end = NULL;
	old.start = start;
	old.end = end;
	if (end == start->next)
	{
		if (start->nb > end->nb)
			swap_elements(a, start);
		return ;
	}
	old_head = a->head;
	work_with_pivot(a, b, &old, &new);
	return_to_a(a, b);
	if (a->head != old_head && a->head->next != old_head)
		sort(a, b, a->head, elem_with_index(a, find_index(a, old_head) - 1));
	if (old.start != old.end)
		sort(a, b, old.start, old.end);
	if (new.start && new.start != new.end)
		sort(a, b, new.start, new.end);
}

void			quick_sort(t_stack *a)
{
	t_stack		b;
	int			i;
	t_number	*cur;

	b.size = 0;
	b.head = NULL;
	b.tail = NULL;
	sort(a, &b, a->head, a->tail);
	cur = a->head;
	i = 0;
	while (cur->next && cur->nb < cur->next->nb)
	{
		cur = cur->next;
		i++;
	}
	if (i != 0)
		i++;
	move_to_top(a, i);
}