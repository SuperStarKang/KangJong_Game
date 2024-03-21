/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 17:34:49 by jongmoon          #+#    #+#             */
/*   Updated: 2024/02/12 19:23:39 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static double	angle_at_index(int x)
{
	double	dx;

	dx = -1 + (double)x / (WIN_WIDTH / 2);
	return (atan(dx));
}

static t_wall	get_wall_column(t_data *data, int x)
{
	double		th;
	t_vec2		ray;
	enum e_dir	hit_dir;
	double		dist;
	t_wall		wall;

	th = angle_at_index(x);
	ray = rotate(data->cam, th);
	dist = raycast(data, ray, &hit_dir);
	wall.z = dist * cos(th);
	wall.texture = data->textures[hit_dir];
	wall.hit_x = get_hit_x(data, vec2_mul(ray, dist), hit_dir);
	wall.length = 1 / wall.z * (WIN_HEIGHT / 2);
	wall.top = WIN_HEIGHT / 2 - wall.length / 2;
	wall.bottom = WIN_HEIGHT / 2 + wall.length / 2;
	return (wall);
}

void	draw_column(t_data *data, int x)
{
	t_wall	wall;
	int		tex_x;
	int		y;
	int		tex_y;
	int		color;

	wall = get_wall_column(data, x);
	tex_x = wall.hit_x * (wall.texture.width - 1);
	y = max(wall.top, 0);
	while (y < min(wall.bottom, WIN_HEIGHT))
	{
		tex_y = (y - wall.top) / wall.length * wall.texture.height;
		color = lerp_color(0, wall.texture.data[tex_y][tex_x],
				fmin(2 / wall.z, 1));
		pixel_put_on_image(data, x, y, color);
		y++;
	}
}
