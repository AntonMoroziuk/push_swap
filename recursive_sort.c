/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 13:56:08 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/19 14:34:33 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_to_b(t_stack *a, t_stack *b, int median)
{
	t_number	*cur;
	int			counter;

	counter = 1;
	while (counter)
	{
		counter = 0;
		cur = a->head;
		while (cur)
		{
			if (cur->nb <= median)
			{
				move_to_top(a, find_index(a, cur));
				ft_putendl("pb");
				push(a, b);
				counter++;
				cur = a->head;
			}
			else
				cur = cur->next;
		}
	}
}

static void	half_to_a(t_stack *a, t_stack *b, int size, int median)
{
	int			i;
	int			r_count;

	i = 0;
	r_count = 0;
	while (i < size / 2)
	{
		while (b->head->nb <= median)
		{
			r_count++;
			rotate(b);
			ft_putendl("rb");
		}
		ft_putendl("pa");
		push(b, a);
		i++;
	}
	while (r_count > 0)
	{
		ft_putendl("rrb");
		rrotate(b);
		r_count--;
	}
}

void		return_to_a(t_stack *a, t_stack *b, int size)
{
	int			i;
	int			median;

	i = -1;
	median = find_median(to_arr(b, size), size);
	if (size == 1)
	{
		ft_putendl("pa");
		push(b, a);
	}
	else if (size <= 3)
		easy_return(a, b, size);
	else
	{
		half_to_a(a, b, size, median);
		sort_in_a(a, b, size / 2);
		return_to_a(a, b, size / 2 + size % 2);
	}
}

static void	sort(t_stack *a, t_stack *b)
{
	int			median;
	int			start_size;

	median = find_median(to_arr(a, a->size), a->size);
	start_size = a->size;
	if (is_sorted(a))
		;
	else if (a->size <= 3)
		easy_sort(a);
	else if (a->size <= 10)
		medium_sort(a);
	else
	{
		push_to_b(a, b, median);
		sort(a, b);
		return_to_a(a, b, start_size / 2 + start_size % 2);
	}
}

void		recursive_sort(t_stack *a)
{
	t_stack		b;

	b.size = 0;
	b.head = NULL;
	b.tail = NULL;
	sort(a, &b);
}
