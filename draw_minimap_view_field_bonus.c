/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap_view_field_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:25:57 by jongmoon          #+#    #+#             */
/*   Updated: 2024/02/12 19:30:36 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	is_wall_on_minimap(t_map minimap, t_ivec2 ipos)
{
	if (ipos.x < 0 || ipos.x >= minimap.width)
	{
		return (0);
	}
	else if (ipos.y < 0 || ipos.y >= minimap.height)
	{
		return (0);
	}
	else if (minimap.data[ipos.y][ipos.x] == WALL)
	{
		return (0);
	}
	return (1);
}

static void	draw_minimap_ray(t_map minimap, t_vec2 ray)
{
	t_vec2	pos;
	t_vec2	dist_over;
	t_vec2	dist_from;
	t_ivec2	ipos;
	t_ivec2	dda_dir;

	pos = make_vec2(minimap.width / 2 + 0.5, minimap.height / 2 + 0.5);
	dist_over = get_dist_over(ray);
	dist_from = get_initial_dist_from(pos, ray, dist_over);
	ipos = make_ivec2(pos.x, pos.y);
	dda_dir = get_dda_dir(ray);
	while (1)
	{
		minimap.data[ipos.y][ipos.x] = RAY;
		ipos = dda_move(ipos, dist_from, dda_dir);
		if (!is_wall_on_minimap(minimap, ipos))
		{
			break ;
		}
		dist_from = dda_add(dist_from, dist_over);
	}
}

static double	deg2rad(double deg)
{
	return (deg / 180 * M_PI);
}

void	draw_minimap_view_field(t_data *data)
{
	t_map	minimap;
	t_vec2	cam;
	double	deg;

	minimap = data->minimap;
	cam = data->cam;
	deg = -45.0;
	while (deg <= 45.0)
	{
		draw_minimap_ray(minimap, rotate(cam, deg2rad(deg)));
		deg += 0.5;
	}
}
