/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:56:32 by kangmlee          #+#    #+#             */
/*   Updated: 2024/02/18 14:02:51 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	is_valid_char(char *str, int *i)
{
	if (str[*i] != '\0' && str[*i] != ',' && str[*i] != ' ' \
		&& !(str[*i] >= '0' && str[*i] <= '9'))
		return (-1);
	while (str[*i] == ' ')
		(*i)++;
	if (str[*i] == ',')
		(*i)++;
	if (str[*i] == ',')
		return (-1);
	while (str[*i] == ' ')
		(*i)++;
	return (0);
}

static int	is_valid_color(int *colors)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (colors[i] < 0 || colors[i] > 255)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

static char	*make_one_color(char *str, char *num, int *i)
{
	int	j;

	j = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		num[j] = str[*i];
		(*i)++;
		j++;
	}
	if (j == 0)
		return (NULL);
	if (j < 3)
	{
		num[j] = ' ';
		j++;
	}
	return (num);
}

static int	_make_color(int *colors, char *str)
{
	int		i;
	int		j;
	char	num[10];

	i = 0;
	j = 0;
	ft_memset(num, 0, sizeof(num));
	while (str[i])
	{
		if (is_valid_char(str, &i) == -1)
			return (-1);
		if (make_one_color(str, num, &i) == 0)
			return (-1);
		colors[j++] = ft_atoi(num);
	}
	if (i == 0 || j != 3 || !is_valid_color(colors))
		return (-1);
	return (0);
}

void	make_color(int *colors, char *color_str, int *pcheck, t_check *check)
{
	color_str = ft_strtrim(color_str, " ");
	if (check->start_lineno != -1)
	{
		on_error("Mixed Order");
	}
	else if (_make_color(colors, color_str) == -1)
	{
		on_error("Invalid Color Type");
	}
	(*pcheck)++;
	free(color_str);
}
