/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_long_nbr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/22 12:32:55 by niduches          #+#    #+#             */
/*   Updated: 2019/10/22 12:59:50 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libftprintf.h"

size_t	put_long_nbr(long long nb, int len)
{
	size_t	n;
	char	c;

	n = 0;
	if (nb > 9 || nb < -9 || len - 1 > 0)
	{
		n += put_long_nbr((nb < 0) ? (-(nb / 10)) : (nb / 10), len - 1);
		c = ((nb < 0) ? (-(nb % 10)) : (nb % 10)) + '0';
		n += write(1, &c, 1);
		return (n);
	}
	c = ((nb < 0) ? (-nb) : nb) + '0';
	n += write(1, &c, 1);
	return (n);
}
