/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_at_indexes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 12:16:49 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/09 12:16:50 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	move_up(t_stack *stack, int i, int ra)
{
	if (ra)
	{
		while (i)
		{
			rotate(stack);
			ft_putendl("ra");
			i--;
		}
	}
	else
		while (i < stack->size)
		{
			rrotate(stack);
			ft_putendl("rra");
			i++;
		}
}

static void	return_back(t_stack *stack, int i, int ra)
{
	if (ra)
	{
		while (i < stack->size)
		{
			rotate(stack);
			ft_putendl("ra");
			i++;
		}
	}
	else
		while (i)
		{
			rrotate(stack);
			ft_putendl("rra");
			i--;
		}
}

void		swap_at_indexes(t_stack *stack, int i)
{
	if (i < stack->size - i + 1)
	{
		move_up(stack, i, 1);
		swap(stack);
		ft_putendl("sa");
		return_back(stack, i, 0);
	}
	else
	{
		move_up(stack, i, 0);
		swap(stack);
		ft_putendl("sa");
		return_back(stack, i, 1);
	}
}