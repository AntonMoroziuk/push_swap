/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 13:28:21 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/06 14:46:57 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		execute(char *command, t_stack *a, t_stack *b)
{
	if (ft_strequ(command, "ra") || ft_strequ(command, "rr"))
		rotate(a);
	if (ft_strequ(command, "rb") || ft_strequ(command, "rr"))
		rotate(b);
	if (ft_strequ(command, "pa"))
		push(b, a);
	if (ft_strequ(command, "pb"))
		push(a, b);
	if (ft_strequ(command, "sa") || ft_strequ(command, "ss"))
		swap(a);
	if (ft_strequ(command, "sb") || ft_strequ(command, "ss"))
		swap(b);
	if (ft_strequ(command, "rra") || ft_strequ(command, "rrr"))
		rrotate(a);
	if (ft_strequ(command, "rrb") || ft_strequ(command, "rrr"))
		rrotate(b);
}

static void	arr_del(char **commands)
{
	int		i;

	i = -1;
	while (commands[++i])
		ft_strdel(&commands[i]);
	free(commands);
}

int			execute_commands(char **commands, t_stack *a)
{
	t_stack	b;
	int		i;

	b.size = 0;
	b.tail = NULL;
	b.head = NULL;
	i = -1;
	while (commands[++i])
		execute(commands[i], a, &b);
	arr_del(commands);
	if (b.size)
	{
		delete_stack(&b);
		return (0);
	}
	return (1);
}
