/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:14:26 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/05 10:19:13 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct	s_stack
{
	int		*numbers;
	int		size;
	int		head;
}				t_stack;

int		get_stack(int argc, char **argv, t_stack *stack);
int		get_commands(char ***commands);
void	execute_commands(char *str, t_stack *stack);

#endif
