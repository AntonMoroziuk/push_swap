/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_in_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 11:34:20 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/19 14:34:58 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	half_to_b(t_stack *a, t_stack *b, int size, int median)
{
	int		i;
	int		r_count;

	i = 0;
	r_count = 0;
	while (i < size / 2 + size % 2)
	{
		while (a->head->nb > median)
		{
			r_count++;
			rotate(a);
			ft_putendl("ra");
		}
		ft_putendl("pb");
		push(a, b);
		i++;
	}
	while (r_count > 0)
	{
		ft_putendl("rra");
		rrotate(a);
		r_count--;
	}
}

static void	ez_sort(t_stack *a, int size)
{
	if (size == 1)
		return ;
	if (size == 2 && a->head->nb > a->head->next->nb)
	{
		ft_putendl("sa");
		swap(a);
	}
}

void		sort_in_a(t_stack *a, t_stack *b, int size)
{
	if (size <= 2)
		ez_sort(a, size);
	else
	{
		half_to_b(a, b, size, find_median(to_arr(a, size), size));
		sort_in_a(a, b, size / 2);
		return_to_a(a, b, size / 2 + size % 2);
	}
}
