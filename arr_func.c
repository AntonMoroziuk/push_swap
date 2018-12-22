/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 13:59:54 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/19 14:35:56 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			*to_arr(t_stack *stack, int size)
{
	int			*res;
	int			i;
	t_number	*cur;

	res = (int*)malloc(sizeof(int) * size);
	cur = stack->head;
	i = -1;
	while (++i < size)
	{
		res[i] = cur->nb;
		cur = cur->next;
	}
	return (res);
}

static void	buble_sort(int *arr, int size)
{
	int		i;
	int		temp;
	int		counter;

	counter = 1;
	while (counter)
	{
		counter = 0;
		i = -1;
		while (++i < size - 1)
			if (arr[i] > arr[i + 1])
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				counter++;
			}
	}
}

int			find_median(int *tab, int size)
{
	int		median;

	buble_sort(tab, size);
	median = tab[(int)(size / 2 - (size % 2 == 0))];
	free(tab);
	return (median);
}
