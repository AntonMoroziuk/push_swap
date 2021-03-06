/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freejoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:44:21 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/06 12:50:45 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_freejoin(char *s1, char *s2)
{
	char	*temp;

	temp = s1;
	s1 = ft_strjoin(s1, s2);
	ft_strdel(&temp);
	return (s1);
}
