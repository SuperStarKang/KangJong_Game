/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangmlee <kangmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 16:38:22 by kangmlee          #+#    #+#             */
/*   Updated: 2024/01/24 15:46:24 by kangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n && str1[i] == str2[i])
	{
		if (!(str1[i]) || !(str2[i]))
			break ;
		i++;
	}
	if (i == n)
	{
		i--;
		return (str1[i] - str2[i]);
	}
	else
		return (str1[i] - str2[i]);
}
