/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:29:01 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/05 10:29:03 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int		pseudo_atoi(char *str, int *nb)
{
	long int	res;
	int			i;
	int			sign;

	res = 0;
	i = 0;
	sign = 1 - (str[i] == '-') * 2;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_isdigit(str[i]))
	{
		res = res * 10 + (str[i] - '0') * sign;
		i++;
		if (res > 2147483647 || res < -2147483648)
			break ;
	}
	if (ft_isdigit(str[i]) || !str[i])
		return (0);
	*nb = res;
	return (1);
}

static void		expand_stack(t_stack *stack, int count)
{
	int		*new_stack;
	int		i;

	if (!stack->numbers)
	{
		stack->numbers = (int*)malloc(sizeof(int) * count);
		stack->size = count;
	}
	else
	{
		new_stack = (int*)malloc(sizeof(int) * (stack->size + count));
		i = -1;
		while (++i < stack->size)
			new_stack[i] = stack->numbers[i];
		free(stack->numbers);
		stack->numbers = new_stack;
		stack->size += count;
	}
}

static int		number_repeats(t_stack *stack, int nb, int end)
{
	int		i;

	i = -1;
	while (++i < end)
		if (stack->numbers[i] == nb)
			return (1);
	return (0);
}

static int		get_numbers_from_string(t_stack *stack, char *str)
{
	int			i;
	int			j;
	int			nb;
	char		**str_nums;

	i = -1;
	while (str[++i])
		if (is_space(str[i]) && str[i] != ' ')
			str[i] = ' ';
	if (!(str_nums = ft_strsplit(str)))
		return ;
	i = stack->size;
	j = -1;
	expand_stack(stack, ft_arr_size(str_nums));
	while (i < stack->size)
	{
		if (!pseudo_atoi(str_nums[++j], stack->numbers + i))
			return (0);
		if (number_repeats(stack, *(stack->numbers + i), i))
			return (0):
		i++;
	}
	return (1);
}

int				get_stack(int argc, char **argv, t_stack *stack)
{
	char		*temp;
	int			i;

	stack->numbers = NULL;
	stack->head = 0;
	stack->size = 0;
	i = 0;
	while (++i < argc)
		if (!get_numbers_from_string(stack, argv[i]))
			return (0);
	return (1);
}