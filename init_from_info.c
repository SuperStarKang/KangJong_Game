/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_from_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:51:31 by jongmoon          #+#    #+#             */
/*   Updated: 2024/02/17 20:18:35 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern t_map	make_map(int width, int height);

static void	init_textures(t_data *data, t_info *info)
{
	data->textures = (t_texture *)malloc(sizeof(t_texture) * 4);
	load_texture(data, NORTH, info->n_path);
	load_texture(data, SOUTH, info->s_path);
	load_texture(data, WEST, info->w_path);
	load_texture(data, EAST, info->e_path);
}

static void	init_color(t_data *data, int *f_color, int *c_color)
{
	data->floor_color = color_from(f_color[0], f_color[1], f_color[2]);
	data->ceiling_color = color_from(c_color[0], c_color[1], c_color[2]);
}

static void	load_map(t_data *data, t_info *info)
{
	t_map	map;
	int		y;
	int		x;

	map = make_map(info->map_x_size, info->map_y_size);
	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			map.data[y][x] = (info->map[y][x] == '1');
			x++;
		}
		y++;
	}
	data->map = map;
}

static void	init_hero(t_data *data, t_hero hero)
{
	static t_vec2	dirs[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

	data->pos = make_vec2(hero.x + 0.5, hero.y + 0.5);
	data->cam = dirs[hero.direction];
}

void	init_data_from_info(t_data *data, t_info *info)
{
	init_textures(data, info);
	init_color(data, info->f_color, info->c_color);
	load_map(data, info);
	init_hero(data, info->hero);
}
