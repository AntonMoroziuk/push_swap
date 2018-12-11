/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 11:33:55 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/08 11:34:02 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void		easy_sort(t_stack *a)
{
	if (a->size == 1 || (a->size == 2 && a->head->nb > a->tail->nb))
		return ;
	else if (a->size == 2 && a->head->nb > a->tail->nb)
		ft_putendl("sa");
	else if (a->head->nb < a->tail->nb && a->tail->nb < a->head->next->nb)
		ft_putendl("pb\nsa\npa");
	else if (a->head->nb > a->head->next->nb && a->head->nb < a->tail->nb)
		ft_putendl("sa");
	else if (a->head->nb < a->head->next->nb && a->head->nb > a->tail->nb)
		ft_putendl("rra");
	else if (a->tail->nb < a->head->nb && a->tail->nb > a->head->next->nb)
		ft_putendl("ra");
	else
		ft_putendl("sa\nrra");
}

static void	sort(t_stack *a)
{
//	 if (a->size <= 3)
//	 	easy_sort(a);
	 //else if (a->size <= 20)
	 medium_sort(a);
//	 else
//	 else
	 	//quick_sort(a);
}

int			main(int argc, char **argv)
{
	t_stack	a;

	if (argc < 2 || !get_stack(argc, argv, &a))
		ft_putendl_fd("Error", 2);
	else if (!is_sorted(&a))
		sort(&a);
	return (0);
}