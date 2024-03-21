/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 19:36:35 by jongmoon          #+#    #+#             */
/*   Updated: 2024/02/18 15:32:19 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cursor(t_data *data)
{
	(void)data;
}

int	motion_notify_hook(int x, int y, void *param)
{
	(void)x;
	(void)y;
	(void)param;
	return (0);
}
