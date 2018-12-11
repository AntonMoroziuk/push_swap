/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 12:22:06 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/06 14:46:10 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	if (stack->size > 1)
	{
		stack->tail->next = stack->head;
		stack->tail = stack->tail->next;
		stack->head = stack->tail->next;
		stack->tail->next = NULL;
	}
}

void	swap(t_stack *stack)
{
	t_number	*temp;

	if (stack->size > 1)
	{
		temp = stack->head->next;
		stack->head->next = stack->head->next->next;
		temp->next = stack->head;
		stack->head = temp;
		if (stack->head == stack->tail)
			stack->tail = stack->head->next;
	}
}

void	push(t_stack *from, t_stack *to)
{
	t_number	*temp;

	if (from->size > 0)
	{
		to->size++;
		from->size--;
		temp = from->head;
		from->head = from->head->next;
		if (from->tail == temp)
			from->tail = NULL;
		temp->next = to->head;
		to->head = temp;
		if (!to->tail)
			to->tail = temp;
	}
}

void	rrotate(t_stack *stack)
{
	t_number	*new_tail;

	if (stack->size > 1)
	{
		new_tail = stack->head;
		while (new_tail->next->next)
			new_tail = new_tail->next;
		stack->tail->next = stack->head;
		stack->head = stack->tail;
		new_tail->next = NULL;
		stack->tail = new_tail;
	}
}
