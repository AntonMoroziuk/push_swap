/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 16:23:39 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/12 11:35:00 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		is_sorted(t_stack *stack)
{
	t_number	*cur;

	cur = stack->head;
	while (cur != stack->tail)
	{
		if (cur->nb > cur->next->nb)
			return (0);
		cur = cur->next;
	}
	return (1);
}
