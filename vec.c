/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:40:43 by jongmoon          #+#    #+#             */
/*   Updated: 2024/02/12 12:42:00 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec2	make_vec2(double x, double y)
{
	t_vec2	v;

	v.x = x;
	v.y = y;
	return (v);
}

t_ivec2	make_ivec2(int x, int y)
{
	t_ivec2	iv;

	iv.x = x;
	iv.y = y;
	return (iv);
}

t_vec2	translate(t_vec2 v0, t_vec2 v1, double t)
{
	v0.x += t * v1.x;
	v0.y += t * v1.y;
	return (v0);
}

t_vec2	rotate(t_vec2 v0, double th)
{
	t_vec2	v1;

	v1.x = v0.x * cos(th) - v0.y * sin(th);
	v1.y = v0.x * sin(th) + v0.y * cos(th);
	return (v1);
}
