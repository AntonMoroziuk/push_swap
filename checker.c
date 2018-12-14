/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:20:21 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/12 11:34:40 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	t_stack	a;
	int		correct_stack;
	char	**commands;

	correct_stack = 1;
	if (argc == 1)
		return (0);
	if (!get_stack(argc, argv, &a))
	{
		ft_putendl_fd("Error", 2);
		correct_stack = 0;
	}
	else if (!get_commands(&commands))
		ft_putendl_fd("Error", 2);
	else if (!execute_commands(commands, &a))
		ft_putendl("KO");
	else if (!is_sorted(&a))
		ft_putendl("KO");
	else
		ft_putendl("OK");
	if (correct_stack)
		delete_stack(&a);
	system("leaks checker");
	return (0);
}
