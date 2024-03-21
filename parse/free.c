/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:35:28 by kangmlee          #+#    #+#             */
/*   Updated: 2024/02/17 21:08:03 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	free_path(t_info *info)
{
	if (info->n_path)
		free(info->n_path);
	if (info->s_path)
		free(info->s_path);
	if (info->w_path)
		free(info->w_path);
	if (info->e_path)
		free(info->e_path);
}

static void	free_map(t_info *info)
{
	int	y;

	y = 0;
	while (y < info->map_y_size && info->map[y] != 0)
	{
		free(info->map[y]);
		y++;
	}
	free(info->map);
}

void	free_info(t_info *info)
{
	free_path(info);
	free_map(info);
}
