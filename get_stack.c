/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:29:01 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/06 14:47:31 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void		lstadd(int nb, t_stack *stack)
{
	t_number	*new;

	new = (t_number*)malloc(sizeof(t_number));
	new->next = NULL;
	new->nb = nb;
	if (!stack->head)
		stack->head = new;
	if (stack->tail)
		stack->tail->next = new;
	stack->tail = new;
	stack->size++;
}

static int		pseudo_atoi(char *str, t_stack *stack)
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
	if (ft_isdigit(str[i]) || str[i])
		return (0);
	lstadd(res, stack);
	return (1);
}

static int		number_repeats(t_stack *stack, int nb)
{
	t_number	*cur;

	cur = stack->head;
	while (cur->next)
	{
		if (cur->nb == nb)
			return (1);
		cur = cur->next;
	}
	return (0);
}

static int		get_numbers_from_string(t_stack *stack, char *str)
{
	int			i;
	char		**str_nums;

	i = -1;
	while (str[++i])
		if (ft_isspace(str[i]) && str[i] != ' ')
			str[i] = ' ';
	if (!(str_nums = ft_strsplit(str, ' ')))
		return (0);
	i = -1;
	while (str_nums[++i])
	{
		if (!pseudo_atoi(str_nums[i], stack))
			return (0);
		if (number_repeats(stack, stack->tail->nb))
			return (0);
	}
	return (1);
}

int				get_stack(int argc, char **argv, t_stack *stack)
{
	int			i;

	stack->size = 0;
	stack->head = NULL;
	stack->tail = NULL;
	i = 0;
	while (++i < argc)
		if (!get_numbers_from_string(stack, argv[i]))
			return (0);
	return (1);
}
