/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:49:12 by jongmoon          #+#    #+#             */
/*   Updated: 2024/02/12 19:46:47 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	close_window(t_data	*data)
{
	teardown(data);
	mlx_destroy_image(data->mlx, data->img.ptr);
	mlx_destroy_window(data->mlx, data->win);
	exit(0);
}

int	key_press_hook(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == KEY_ESCAPE)
		close_window(data);
	else if (keycode == KEY_LEFT)
		data->is_lr_pressed = -1;
	else if (keycode == KEY_RIGHT)
		data->is_lr_pressed = 1;
	else if (keycode == KEY_W)
		data->is_ws_pressed = 1;
	else if (keycode == KEY_S)
		data->is_ws_pressed = -1;
	else if (keycode == KEY_A)
		data->is_ad_pressed = -1;
	else if (keycode == KEY_D)
		data->is_ad_pressed = 1;
	return (0);
}

int	key_release_hook(int keycode, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
		data->is_lr_pressed = 0;
	else if (keycode == KEY_W || keycode == KEY_S)
		data->is_ws_pressed = 0;
	else if (keycode == KEY_A || keycode == KEY_D)
		data->is_ad_pressed = 0;
	return (0);
}

int	destroy_notify_hook(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	close_window(data);
	return (0);
}

int	loop_hook(void *param)
{
	static const double	t = 1.0 / 16;
	t_data				*data;
	t_vec2				new_dir;

	data = (t_data *)param;
	data->tick++;
	if (data->tick % 250 == 0)
	{
		if (data->is_ws_pressed || data->is_ad_pressed)
		{
			new_dir = vec2_add(
					vec2_mul(data->cam, data->is_ws_pressed),
					vec2_mul(rotate(data->cam, M_PI_2), data->is_ad_pressed)
					);
			new_dir = vec2_normalize(new_dir);
			data->pos = move(data->map, data->pos, new_dir, t);
		}
		if (data->is_lr_pressed)
		{
			data->cam = rotate(data->cam, t * data->is_lr_pressed);
		}
		draw_image(data);
	}
	return (0);
}
