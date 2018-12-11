/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_commands.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 11:20:41 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/06 12:01:53 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

static int	split_and_check(char ***commands)
{
	char	*temp;
	int		i;

	temp = **commands;
	*commands = ft_strsplit(**commands, '\n');
	i = -1;
	while ((*commands)[++i])
		if (!correct((*commands)[i]))
			return (0);
	return (1);
}

int			get_commands(char ***commands)
{
	char	*command;
	char	*buf;
	int		i;
	int		rs;

	buf = ft_strnew(100);
	command = ft_strnew(100);
	while ((rs = read(0, buf, 100)))
	{
		buf[rs] = '\0';
		i = -1;
		while (++i <= rs)
			command[i] = buf[i];
		**commands = ft_freejoin(**commands, command);
	}
	ft_strdel(&command);
	if ((**commands)[ft_strlen(**commands) - 1] != '\n' )
		return (0);
	(**commands)[ft_strlen(**commands) - 1] = '\0';
	return (split_and_check(commands));
}
