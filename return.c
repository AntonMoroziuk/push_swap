/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 14:56:48 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/19 14:34:42 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	other_2(t_stack *a, t_stack *b)
{
	if (b->head->nb < b->head->next->nb &&
		b->head->nb > b->head->next->next->nb)
	{
		ft_printf("rb\npa\nrrb\npa\npa\n");
		rotate(b);
		push(b, a);
		rrotate(b);
		push(b, a);
		push(b, a);
	}
	else
	{
		ft_putendl("pa");
		push(b, a);
		if (b->head->nb < b->head->next->nb)
		{
			ft_putendl("sb");
			swap(b);
		}
		ft_putendl("pa\npa");
		push(b, a);
		push(b, a);
	}
}

static void	other(t_stack *a, t_stack *b)
{
	if (b->head->nb < b->head->next->next->nb &&
		b->head->next->nb > b->head->next->next->nb)
	{
		ft_printf("rb\npa\npa\nrrb\npa\n");
		rotate(b);
		push(b, a);
		push(b, a);
		rrotate(b);
		push(b, a);
	}
	else if (b->head->nb > b->head->next->nb &&
		b->head->nb < b->head->next->next->nb)
	{
		ft_printf("rb\nsb\npa\nrrb\npa\npa\n");
		rotate(b);
		swap(b);
		push(b, a);
		rrotate(b);
		push(b, a);
		push(b, a);
	}
	else
		other_2(a, b);
}

void		easy_return(t_stack *a, t_stack *b, int b_size)
{
	if (b_size == 2)
	{
		if (b->head->nb < b->head->next->nb)
		{
			ft_printf("sb\n");
			swap(b);
		}
		ft_printf("pa\npa\n");
		push(b, a);
		push(b, a);
	}
	else if (b->head->next->nb > b->head->nb &&
			b->head->next->next->nb > b->head->next->nb)
	{
		ft_printf("rb\nsb\npa\npa\nrrb\npa\n");
		rotate(b);
		swap(b);
		push(b, a);
		push(b, a);
		rrotate(b);
		push(b, a);
	}
	else
		other(a, b);
}
