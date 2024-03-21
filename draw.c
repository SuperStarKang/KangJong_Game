/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:54:58 by jongmoon          #+#    #+#             */
/*   Updated: 2024/02/17 15:24:32 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	pixel_put_on_image(t_data *data, int x, int y, int color)
{
	t_img	*img;
	int		offset;
	char	*dest;

	img = &data->img;
	offset = y * img->size_line + x * (img->bits_per_pixel / 8);
	dest = img->addr + offset;
	*(unsigned int *)dest = color;
}

static void	draw_background(t_data *data)
{
	int		x;
	int		y;
	int		color;

	x = 0;
	while (x < WIN_WIDTH)
	{
		y = 0;
		while (y < WIN_HEIGHT / 2)
		{
			color = lerp_color(data->ceiling_color, 0,
					(double)y / (WIN_HEIGHT / 2));
			pixel_put_on_image(data, x, y, color);
			y++;
		}
		while (y < WIN_HEIGHT)
		{
			color = lerp_color(0, data->floor_color,
					(double)(y - WIN_HEIGHT / 2) / (WIN_HEIGHT / 2));
			pixel_put_on_image(data, x, y, color);
			y++;
		}
		x++;
	}
}

void	draw_image(t_data *data)
{
	int	x;

	draw_background(data);
	x = 0;
	while (x < WIN_WIDTH)
	{
		draw_column(data, x);
		x++;
	}
	draw_minimap(data, make_ivec2(10, 10), 5);
	mlx_put_image_to_window(data->mlx, data->win, data->img.ptr, 0, 0);
}
