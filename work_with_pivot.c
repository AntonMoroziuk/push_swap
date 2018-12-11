/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_pivot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 13:29:36 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/09 16:23:51 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	not_smallest(t_number *start, t_number *end)
{
	int			pivot;
	t_number	*cur;

	cur = start;
	pivot = cur->nb;
	cur = cur->next;
	while (cur != end->next)
	{
		if (cur->nb < pivot)
			return (1);
		cur = cur->next;
	}
	return (0);
}

void		work_with_pivot(t_stack *a, t_stack *b,
	t_group *old, t_group *new)
{
	t_number	*cur;
	t_number	*stop;

	if (not_smallest(old->start, old->end))
	{
		cur = old->start->next;
		stop = old->end->next;
		move_to_top(a, find_index(a, old->start));
		push(a, b);
		ft_putendl("pb");
		while (cur != stop)
			if (cur->nb < b->tail->nb)
			{
				if (new->start && cur != a->head)
					new->start = a->head;
				move_to_top(a, find_index(a, cur));
				ft_putendl("pb");
				push(a, b);
				cur = a->head;
			}
			else
				cur = cur->next;
		new->end = a->tail;
		old->start = a->head;
	}
}
