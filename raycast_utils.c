/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:17:15 by jongmoon          #+#    #+#             */
/*   Updated: 2024/02/12 19:48:13 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec2	get_dist_over(t_vec2 ray)
{
	t_vec2	dist_over;

	if (ray.x == 0.0)
	{
		dist_over.x = INFINITY;
	}
	else
	{
		dist_over.x = fabs(1 / ray.x);
	}
	if (ray.y == 0.0)
	{
		dist_over.y = INFINITY;
	}
	else
	{
		dist_over.y = fabs(1 / ray.y);
	}
	return (dist_over);
}

t_vec2	get_initial_dist_from(t_vec2 pos, t_vec2 ray, t_vec2 dist_over)
{
	t_vec2	dist_from;

	if (ray.x > 0)
	{
		dist_from.x = dist_over.x * ((int)pos.x + 1 - pos.x);
	}
	else
	{
		dist_from.x = dist_over.x * (pos.x - (int)pos.x);
	}
	if (ray.y > 0)
	{
		dist_from.y = dist_over.y * ((int)pos.y + 1 - pos.y);
	}
	else
	{
		dist_from.y = dist_over.y * (pos.y - (int)pos.y);
	}
	return (dist_from);
}

t_ivec2	get_dda_dir(t_vec2 ray)
{
	t_ivec2	dir;

	if (ray.x > 0.0)
	{
		dir.x = 1;
	}
	else
	{
		dir.x = -1;
	}
	if (ray.y > 0.0)
	{
		dir.y = 1;
	}
	else
	{
		dir.y = -1;
	}
	return (dir);
}

t_ivec2	dda_move(t_ivec2 pos, t_vec2 dist_from, t_ivec2 dda_dir)
{
	if (dist_from.x < dist_from.y)
	{
		pos.x += dda_dir.x;
	}
	else
	{
		pos.y += dda_dir.y;
	}
	return (pos);
}

t_vec2	dda_add(t_vec2 dist_from, t_vec2 dist_over)
{
	if (dist_from.x < dist_from.y)
	{
		dist_from.x += dist_over.x;
	}
	else
	{
		dist_from.y += dist_over.y;
	}
	return (dist_from);
}
