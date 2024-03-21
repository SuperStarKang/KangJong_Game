/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: superstar <superstar@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 06:29:54 by kangmlee          #+#    #+#             */
/*   Updated: 2024/02/19 16:40:42 by superstar        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static int	check_direction(char ch)
{
	if (ch == 'N')
		return (NORTH);
	else if (ch == 'S')
		return (SOUTH);
	else if (ch == 'W')
		return (WEST);
	else
		return (EAST);
}

static void	init_hero(t_info *info, char *buffer, int x, int y)
{
	if (info->hero.direction != -1)
	{
		on_error("Too Many Hero");
	}
	info->hero.x = x;
	info->hero.y = y;
	info->hero.direction = check_direction(buffer[x]);
	info->map[y][x] = '0';
}

static void	make_map(t_info *info, char *buffer, int y)
{
	int	x;

	x = 0;
	while (buffer[x] && x < info->map_x_size)
	{
		if (buffer[x] == '1' || buffer[x] == '0' || buffer[x] == ' ')
			info->map[y][x] = buffer[x];
		else if (buffer[x] == 'N' || buffer[x] == 'S'
			|| buffer[x] == 'W' || buffer[x] == 'E')
			init_hero(info, buffer, x, y);
		else
			on_error("Invalid Map");
		x++;
	}
	while (x < info->map_x_size)
	{
		info->map[y][x] = ' ';
		x++;
	}
	info->map[y][x] = '\0';
}

static char	*seek_map(t_info *info, int fd)
{
	char	*buffer;
	int		i;

	buffer = get_next_line(fd);
	i = 0;
	while (buffer && i < info->map_location)
	{
		free(buffer);
		buffer = get_next_line(fd);
		i++;
	}
	return (buffer);
}

void	map_parse(t_info *info, char *file)
{
	int		fd;
	char	*buffer;
	int		y;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		on_error("Invalid File");
	}
	buffer = seek_map(info, fd);
	info->map = (char **)malloc(sizeof(char *) * info->map_y_size);
	y = 0;
	while (y < info->map_y_size)
	{
		info->map[y] = (char *)malloc(sizeof(char) * (info->map_x_size + 1));
		make_map(info, buffer, y);
		free(buffer);
		buffer = get_next_line(fd);
		y++;
	}
	if (buffer)
		free(buffer);
	if (info->hero.direction == -1)
	{
		on_error("No Hero");
	}
	close(fd);
}
