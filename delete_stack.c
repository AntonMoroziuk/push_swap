/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 14:55:07 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/08 14:55:10 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	delete_stack(t_stack *stack)
{
	t_number	*temp;

	temp = stack->head;
	while (temp)
	{
		stack->head = temp;
		temp = stack->head->next;
		free(stack->head);
	}
}