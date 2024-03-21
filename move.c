/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:50:59 by jongmoon          #+#    #+#             */
/*   Updated: 2024/02/12 21:21:09 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec2	move(t_map map, t_vec2 pos, t_vec2 dir, double t)
{
	t_vec2	new_pos;

	new_pos = translate(pos, dir, t);
	if (new_pos.x < 0 || new_pos.x >= map.width)
	{
		return (pos);
	}
	else if (new_pos.y < 0 || new_pos.y >= map.height)
	{
		return (pos);
	}
	return (new_pos);
}
