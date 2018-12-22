/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 15:40:56 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/19 12:04:31 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find_index(t_stack *stack, t_number *nb)
{
	int			i;
	t_number	*cur;

	i = 0;
	cur = stack->head;
	while (cur != nb)
	{
		i++;
		cur = cur->next;
	}
	return (i);
}
