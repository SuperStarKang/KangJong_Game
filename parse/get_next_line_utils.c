/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: superstar <superstar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:37:57 by kangmlee          #+#    #+#             */
/*   Updated: 2024/01/25 23:00:31 by superstar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	if (*str)
		free(*str);
	*str = 0;
	return (0);
}

int	has_newline(char *backup)
{
	int	i;

	if (!(backup))
		return (-1);
	i = 0;
	while (backup[i])
	{
		if (backup[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char		*str;
	size_t		s1_len;
	size_t		s2_len;
	size_t		i;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!(str))
		return (ft_free(&s1));
	i = 0;
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	while (i < s2_len + s1_len)
	{
		str[i] = s2[i - s1_len];
		i++;
	}
	str[i] = '\0';
	s1 = ft_free(&s1);
	return (str);
}
