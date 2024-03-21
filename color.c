/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:27:16 by jongmoon          #+#    #+#             */
/*   Updated: 2024/02/12 12:36:24 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	color_from(int r, int g, int b)
{
	r &= 0xff;
	g &= 0xff;
	b &= 0xff;
	return (r << 020 | g << 010 | b << 000);
}

static t_color	decomposite(int color)
{
	t_color	c;

	c.r = color >> 020 & 0xff;
	c.g = color >> 010 & 0xff;
	c.b = color >> 000 & 0xff;
	return (c);
}

static double	lerp(double v0, double v1, double t)
{
	return ((1 - t) * v0 + t * v1);
}

int	lerp_color(int color0, int color1, double t)
{
	t_color	c0;
	t_color	c1;
	int		r;
	int		g;
	int		b;

	c0 = decomposite(color0);
	c1 = decomposite(color1);
	r = lerp(c0.r, c1.r, t);
	g = lerp(c0.g, c1.g, t);
	b = lerp(c0.b, c1.b, t);
	return (color_from(r, g, b));
}
