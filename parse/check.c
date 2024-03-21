/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:00:48 by kangmlee          #+#    #+#             */
/*   Updated: 2024/02/17 21:45:51 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	map_middle_check(t_info *info, int x, int y)
{
	if (info->map[y][x] == ' ')
	{
		if (x > 0 && info->map[y][x - 1] != ' ' && info->map[y][x - 1] != '1')
			on_error("Map Error");
		if (x < info->map_x_size && info->map[y][x + 1] != ' '
			&& info->map[y][x + 1] != '1' && info->map[y][x + 1] != '\0')
			on_error("Map Error");
		if (info->map[y - 1][x] != ' ' && info->map[y - 1][x] != '1')
			on_error("Map Error");
		if (info->map[y + 1][x] != ' ' && info->map[y + 1][x] != '1')
			on_error("Map Error");
	}
	else if (info->map[y][x] == '0')
	{
		if (x == 0 || x == info->map_x_size - 1)
			on_error("Map Error");
	}
}

int	check_map(t_info *info)
{
	int	y;
	int	x;

	y = 0;
	while (y < info->map_y_size)
	{
		x = 0;
		while (x < info->map_x_size)
		{
			if (y == 0 || y == info->map_y_size - 1)
			{
				if (info->map[y][x] != ' ' && info->map[y][x] != '1')
				{
					on_error("Not Surrounded By Wall");
				}
			}
			else
			{
				map_middle_check(info, x, y);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	check_file_name(char *file, char *ber)
{
	int	idx;

	idx = ft_strlen(file) - 4;
	if (idx < 0)
		return (-1);
	if (ft_strncmp(file + idx, ber, 4))
	{
		return (-1);
	}
	return (0);
}
