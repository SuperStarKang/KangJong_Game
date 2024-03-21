/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:15:53 by jongmoon          #+#    #+#             */
/*   Updated: 2024/02/12 21:16:14 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_wall_on_map(t_map map, t_ivec2 pos)
{
	if (pos.x < 0 || pos.x >= map.width)
	{
		return (1);
	}
	else if (pos.y < 0 || pos.y >= map.height)
	{
		return (1);
	}
	return (map.data[pos.y][pos.x]);
}

static enum e_dir	get_hit_dir(t_vec2 dist_from, t_vec2 ray)
{
	if (dist_from.x < dist_from.y)
	{
		if (ray.x > 0)
		{
			return (WEST);
		}
		else
		{
			return (EAST);
		}
	}
	else
	{
		if (ray.y > 0)
		{
			return (NORTH);
		}
		else
		{
			return (SOUTH);
		}
	}
}

double	raycast(t_data *data, t_vec2 ray, enum e_dir *hit_dir)
{
	t_vec2	dist_over;
	t_vec2	dist_from;
	t_ivec2	pos;
	t_ivec2	dda_dir;
	t_map	map;

	dist_over = get_dist_over(ray);
	dist_from = get_initial_dist_from(data->pos, ray, dist_over);
	pos = make_ivec2(data->pos.x, data->pos.y);
	dda_dir = get_dda_dir(ray);
	map = data->map;
	while (1)
	{
		pos = dda_move(pos, dist_from, dda_dir);
		if (is_wall_on_map(map, pos))
		{
			break ;
		}
		dist_from = dda_add(dist_from, dist_over);
	}
	*hit_dir = get_hit_dir(dist_from, ray);
	return (fmin(dist_from.x, dist_from.y));
}

double	get_hit_x(t_data *data, t_vec2 displacement, enum e_dir hit_dir)
{
	double		hit_x;

	if (hit_dir == NORTH || hit_dir == SOUTH)
	{
		hit_x = data->pos.x + displacement.x;
	}
	else
	{
		hit_x = data->pos.y + displacement.y;
	}
	hit_x -= (int)hit_x;
	if (hit_dir == NORTH || hit_dir == EAST)
	{
		hit_x = 1 - hit_x;
	}
	return (hit_x);
}
