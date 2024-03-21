/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:52:46 by jongmoon          #+#    #+#             */
/*   Updated: 2024/02/12 19:33:01 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern void	draw_minimap_view_field(t_data *data);

static void	draw_minimap_background(t_data *data)
{
	t_map	minimap;
	int		y;
	int		x;

	minimap = data->minimap;
	y = 0;
	while (y < minimap.height)
	{
		x = 0;
		while (x < minimap.width)
		{
			minimap.data[y][x] = BACKGROUND;
			x++;
		}
		y++;
	}
}

static int	is_wall_on_map(t_map map, t_vec2 pos, double dx, double dy)
{
	pos = vec2_add(pos, make_vec2(dx, dy));
	if (pos.x < 0 || pos.x >= map.width)
	{
		return (0);
	}
	else if (pos.y < 0 || pos.y >= map.height)
	{
		return (0);
	}
	return (map.data[(int)pos.y][(int)pos.x]);
}

static void	draw_minimap_walls(t_data *data, const int size)
{
	t_map	minimap;
	int		y;
	int		x;
	double	dy;
	double	dx;

	minimap = data->minimap;
	y = 0;
	while (y < minimap.height)
	{
		x = 0;
		while (x < minimap.width)
		{
			dy = (double)(y - minimap.height / 2) / size;
			dx = (double)(x - minimap.width / 2) / size;
			if (is_wall_on_map(data->map, data->pos, dx, dy))
			{
				minimap.data[y][x] = WALL;
			}
			x++;
		}
		y++;
	}
}

static void	draw_minimap_character(t_data *data, const int size)
{
	t_map	minimap;
	t_ivec2	center;
	int		y;
	int		x;

	minimap = data->minimap;
	center = make_ivec2(minimap.width / 2, minimap.height / 2);
	y = -(size / 2);
	while (y <= size / 2)
	{
		x = -(size / 2);
		while (x <= size / 2)
		{
			minimap.data[center.y + y][center.x + x] = CHARACTER;
			x++;
		}
		y++;
	}
}

void	draw_minimap(t_data *data, const t_ivec2 offset, const int size)
{
	static int	colors[4] = {0x000000, 0x777777, 0x777700, 0x00ff00};
	t_map		minimap;
	int			y;
	int			x;
	int			type;

	draw_minimap_background(data);
	draw_minimap_walls(data, size);
	draw_minimap_view_field(data);
	draw_minimap_character(data, size);
	minimap = data->minimap;
	y = 0;
	while (y < minimap.height)
	{
		x = 0;
		while (x < minimap.width)
		{
			type = minimap.data[y][x];
			pixel_put_on_image(data, x + offset.x, y + offset.y, colors[type]);
			x++;
		}
		y++;
	}
}
