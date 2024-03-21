/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:44:51 by jongmoon          #+#    #+#             */
/*   Updated: 2024/02/12 12:45:46 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_vec2	vec2_add(t_vec2 v0, t_vec2 v1)
{
	v0.x += v1.x;
	v0.y += v1.y;
	return (v0);
}

t_vec2	vec2_mul(t_vec2 v, double k)
{
	v.x *= k;
	v.y *= k;
	return (v);
}

double	vec2_length(t_vec2 v)
{
	return (sqrt(v.x * v.x + v.y * v.y));
}

t_vec2	vec2_normalize(t_vec2 v)
{
	double	length;

	length = vec2_length(v);
	v.x /= length;
	v.y /= length;
	return (v);
}
