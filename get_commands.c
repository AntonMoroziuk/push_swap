/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:20:41 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/05 11:20:50 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

static int	correct(char *command)
{
	if (!ft_strequ(command, "ra") &&
		!ft_strequ(command, "rb") &&
		!ft_strequ(command, "rr") &&
		!ft_strequ(command, "pb") &&
		!ft_strequ(command, "pa") &&
		!ft_strequ(command, "sa") &&
		!ft_strequ(command, "sb") &&
		!ft_strequ(command, "ss") &&
		!ft_strequ(command, "rra") &&
		!ft_strequ(command, "rrb") &&
		!ft_strequ(command, "rrr"))
		return (0);
	return (1);
}

int			get_commands(char **commands)
{
	char	*command;
	char	*temp;

	while (get_next_line(1, &command))
	{
		if (ft_strlen(command) < 2 || ft_strlen(command) > 3)
			return (0);
		if (!correct(command))
			return (0);
		if (**commands)
		{
			temp = *commands;
			*commands = ft_strjoin(*commands, " ");
			ft_strdel(&temp);
		}
		temp = *commands;
		*commands = ft_strjoin(*commands, command);
		ft_strdel(&temp);
	}
	ft_strdel(&command);
}