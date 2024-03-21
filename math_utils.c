/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 21:30:35 by jongmoon          #+#    #+#             */
/*   Updated: 2024/02/06 09:19:36 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	max(int a, int b)
{
	if (a > b)
	{
		return (a);
	}
	return (b);
}

int	min(int a, int b)
{
	if (a < b)
	{
		return (a);
	}
	return (b);
}

double	fmax(double a, double b)
{
	if (a > b)
	{
		return (a);
	}
	return (b);
}

double	fmin(double a, double b)
{
	if (a < b)
	{
		return (a);
	}
	return (b);
}

double	fclamp(double v, double lo, double hi)
{
	return (fmax(lo, fmin(hi, v)));
}
