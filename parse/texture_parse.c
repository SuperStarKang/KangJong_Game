/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 07:06:30 by kangmlee          #+#    #+#             */
/*   Updated: 2024/02/18 15:23:23 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	init_check(t_check *check)
{
	check->f_color = 0;
	check->c_color = 0;
	check->start_lineno = -1;
	check->end_lineno = -1;
}

static int	get_efficient_x_size(char *str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && str[i] == ' ')
	{
		i--;
	}
	return (i + 1);
}

static void	type_check(t_info *info, t_check *check, char *buffer, int i)
{
	static int	lineno = 0;

	if (!(ft_strncmp(buffer + i, "NO ", 3)))
		make_path(&info->n_path, buffer + i + 3, check);
	else if (!(ft_strncmp(buffer + i, "SO ", 3)))
		make_path(&info->s_path, buffer + i + 3, check);
	else if (!(ft_strncmp(buffer + i, "WE ", 3)))
		make_path(&info->w_path, buffer + i + 3, check);
	else if (!(ft_strncmp(buffer + i, "EA ", 3)))
		make_path(&info->e_path, buffer + i + 3, check);
	else if (!(ft_strncmp(buffer + i, "F ", 2)))
		make_color(info->f_color, buffer + i + 2, &check->f_color, check);
	else if (!(ft_strncmp(buffer + i, "C ", 2)))
		make_color(info->c_color, buffer + i + 2, &check->c_color, check);
	else if (buffer[i] == '1' || buffer[i] == '0')
	{
		if (check->start_lineno == -1)
			check->start_lineno = lineno;
		check->end_lineno = lineno + 1;
		info->map_x_size = max(info->map_x_size, get_efficient_x_size(buffer));
	}
	else if (buffer[i] != '\0'
		|| (buffer[i] == '\0' && i > 0 && check->start_lineno == -1))
		on_error("Wrong Character");
	lineno++;
}

static int	is_valid_element_count(t_info *info, t_check *check)
{
	if (info->n_path == NULL || info->s_path == NULL
		|| info->w_path == NULL || info->e_path == NULL)
	{
		return (0);
	}
	else if (check->f_color != 1 || check->c_color != 1)
	{
		return (0);
	}
	else if (check->start_lineno == -1)
	{
		return (0);
	}
	return (1);
}

void	format_check(t_info *info, char *file)
{
	int		fd;
	t_check	check;
	char	*buffer;
	int		i;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		on_error("Invalid File");
	init_check(&check);
	buffer = get_next_line(fd);
	while (buffer)
	{
		i = 0;
		while (buffer[i] == ' ')
			i++;
		type_check(info, &check, buffer, i);
		free(buffer);
		buffer = get_next_line(fd);
	}
	if (!is_valid_element_count(info, &check))
		on_error("Invalid Element Count");
	info->map_location = check.start_lineno;
	info->map_y_size = check.end_lineno - check.start_lineno;
	close(fd);
}
