/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:20:21 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/06 14:45:48 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			main(int argc, char **argv)
{
	t_stack	a;
	int		correct_stack;
	char	**commands;

	commands = (char**)malloc(sizeof(char*));
	*commands = ft_strnew(0);
	correct_stack = 1;
	if (argc < 2 || !get_stack(argc, argv, &a))
	{
		ft_putendl_fd("Error", 2);
		correct_stack = 0;
	}
	else if (is_sorted(&a))
		ft_putendl("OK");
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
	//system("leaks checker");
	return (0);
}
