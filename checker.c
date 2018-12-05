/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:20:21 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/05 10:20:23 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_sorted(t_stack stack)
{
	int		i;
	int		k;
	int		j;

	j = 0;
	while (j < stack.size - 1)
	{
		i = stack.head + j + 1;
		if (i >= stack.size)
			i = i % stack.size;
		k = stack.head + j + 1;
		if (k >= stack.size)
			k = k % stack.size;
		if (stack.numbers[k] > stack.numbers[i])
			return (0);
		j++;
	}
	return (1);
}

int			main(int argc, char **argv)
{
	t_stack	a;
	char	*commands;

	if (argc < 2 || !get_stack(argc, argv, &a))
		ft_putendl("Error\n");
	if (!get_commands(&commands))
		ft_putendl("Error\n");
	if (!execute_commands(commands, &a))
		ft_putendl("KO");
	else if (!is_sorted(a))
		ft_putendl("KO");
	else
		ft_putendl("OK");
	return (0);
}