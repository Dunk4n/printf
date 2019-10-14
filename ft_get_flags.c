/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: niduches <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 15:55:32 by niduches          #+#    #+#             */
/*   Updated: 2019/10/13 18:06:21 by niduches         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	ft_atoi_cust(const char *str, size_t *indice, va_list list)
{
	size_t	i;
	long	nb;

	if (*str == '*')
	{
		(*indice)++;
		return (va_arg(list, int));
	}
	i = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
		nb = (int)(nb * 10 + str[i++] - '0');
	if (i)
		*indice += i;
	return (nb);
}

static void	set_precast(int *flags, const char *str, size_t size)
{
	char	end;
	size_t	i;

	i = 0;
	end = '\0';
	while (i < size)
	{
		if (str[i] == 'l' || str[i] == 'h')
		{
			end = (str[i] == 'l') ? 'l' : 'h';
			(str[i] == 'l') ?
(flags[4] = (flags[4] + 1) % 2) : (flags[5] = (flags[5] + 1) % 2);
		}
		i++;
	}
	if (end == 'l')
		flags[5] = 0;
	if (end == 'h')
		flags[4] = 0;
}

void		get_flags(int *flags, const char *str, size_t size, va_list list)
{
	size_t	i;
	size_t	j;

	i = 0;
	set_precast(flags, str, size);
	while (i < size)
	{
		j = 0;
		if ((str[i] > '0' && str[i] <= '9') || str[i] == '*')
			flags[NB_FLAGS] = ft_atoi_cust(str + i, &i, list);
		while (FLAGS[j])
		{
			if (FLAGS[j] == str[i] && str[i] != 'l' && str[i] != 'h')
			{
				flags[j]++;
				if (str[i] == '.')
					flags[j] = ft_atoi_cust(str + i + 1, &i, list);
			}
			j++;
		}
		i++;
	}
	if (flags[0])
		flags[1] = 0;
}
