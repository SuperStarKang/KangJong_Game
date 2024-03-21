/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:30:27 by jongmoon          #+#    #+#             */
/*   Updated: 2024/02/18 15:32:57 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	init_data(&data, argc, argv);
	init_cursor(&data);
	mlx_hook(data.win, KEY_PRESS, 0, key_press_hook, &data);
	mlx_hook(data.win, KEY_RELEASE, 0, key_release_hook, &data);
	mlx_hook(data.win, MOTION_NOTIFY, 0, motion_notify_hook, &data);
	mlx_hook(data.win, DESTROY_NOTIFY, 0, destroy_notify_hook, &data);
	mlx_loop_hook(data.mlx, loop_hook, &data);
	mlx_loop(data.mlx);
	return (0);
}
