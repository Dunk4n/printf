/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isconv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 14:03:10 by niduches          #+#    #+#             */
/*   Updated: 2019/10/19 16:12:26 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

int		ft_isconv(char c)
{
	size_t	i;

	i = 0;
	while (CONVERSIONS[i])
	{
		if (c == CONVERSIONS[i])
			return (1);
		i++;
	}
	i = 0;
	while (CONVERSIONS_BONUS[i])
	{
		if (c == CONVERSIONS_BONUS[i])
			return (1);
		i++;
	}
	return (0);
}
