/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 13:02:49 by niduches          #+#    #+#             */
/*   Updated: 2019/10/19 16:12:27 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libftprintf.h"

int		ft_isflag(char c)
{
	size_t	i;

	i = 0;
	while (FLAGS[i])
	{
		if (c == FLAGS[i])
			return (1);
		i++;
	}
	return (0);
}
