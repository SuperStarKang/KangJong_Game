/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:47:13 by jongmoon          #+#    #+#             */
/*   Updated: 2024/02/12 22:09:43 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_vec2	get_nearest(t_vec2 pos, int x, int y)
{
	t_vec2	nearest;

	nearest.x = fclamp(pos.x, x, x + 1) - pos.x;
	nearest.y = fclamp(pos.y, y, y + 1) - pos.y;
	return (nearest);
}

static t_vec2	resolve_overlap(t_vec2 pos, t_vec2 nearest, const double r)
{
	double	dist;
	double	overlap;
	t_vec2	backward;

	dist = vec2_length(nearest);
	if (dist < r)
	{
		overlap = r - dist;
		backward = vec2_mul(vec2_normalize(nearest), -overlap);
		pos = vec2_add(pos, backward);
	}
	return (pos);
}

static t_vec2	detect_collision(t_map map, t_vec2 pos, const double r)
{
	int		y;
	int		x;
	t_vec2	nearest;

	y = pos.y - 1;
	while (y <= pos.y + 1)
	{
		x = pos.x - 1;
		while (x <= pos.x + 1)
		{
			if (map.data[y][x] != 0)
			{
				nearest = get_nearest(pos, x, y);
				pos = resolve_overlap(pos, nearest, r);
			}
			x++;
		}
		y++;
	}
	return (pos);
}

t_vec2	move(t_map map, t_vec2 pos, t_vec2 dir, double t)
{
	pos = translate(pos, dir, t);
	pos = detect_collision(map, pos, 0.5);
	return (pos);
}
