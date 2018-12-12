/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_top.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:21:24 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/12 11:33:38 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		move_to_top(t_stack *a, int elem_idx)
{
	if (elem_idx == 0 || elem_idx >= a->size)
		return ;
	if (a->size - elem_idx > elem_idx)
	{
		while (elem_idx > 0)
		{
			rotate(a);
			ft_putendl("ra");
			elem_idx--;
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
