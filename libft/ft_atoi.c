/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangmlee <kangmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 03:24:43 by kangmlee          #+#    #+#             */
/*   Updated: 2024/01/26 16:51:21 by kangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int				i;
	int				is_minus;
	unsigned long	number;

	i = 0;
	is_minus = 1;
	number = 0;
	while (str[i] != 0 && ft_isspace(str[i]) != 0)
		i++;
	if (str[i] != 0 && (str[i] == '+' || str[i] == '-'))
	{
		if (str[i] == '-')
			is_minus *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		number = number * 10 + str[i++] - '0';
	if (number > 9223372036854775807 && is_minus == 1)
		return (-1);
	if (number - 1 > 9223372036854775807 && is_minus == -1)
		return (0);
	return (is_minus * number);
}
