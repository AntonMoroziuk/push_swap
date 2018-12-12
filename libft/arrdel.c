/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrdel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 11:45:06 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/12 11:46:02 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	arrdel(char **arr)
{
	int		i;

	i = -1;
	while (arr[++i])
		ft_strdel(&arr[i]);
	free(arr);
}
