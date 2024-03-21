/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:52:47 by jongmoon          #+#    #+#             */
/*   Updated: 2024/02/18 15:33:12 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cursor(t_data *data)
{
	mlx_mouse_hide();
	mlx_mouse_move(data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
}

int	motion_notify_hook(int x, int y, void *param)
{
	t_data	*data;
	double	dx;
	double	th;

	(void)y;
	data = (t_data *)param;
	dx = (double)(x - WIN_WIDTH / 2) / (WIN_WIDTH / 2);
	th = atan(dx);
	data->cam = rotate(data->cam, th);
	mlx_mouse_move(data->win, WIN_WIDTH / 2, WIN_HEIGHT / 2);
	return (0);
}
