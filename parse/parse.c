/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:33:04 by kangmlee          #+#    #+#             */
/*   Updated: 2024/02/18 14:41:23 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

static void	init_info(t_info *info)
{
	info->map_location = 0;
	info->n_path = NULL;
	info->s_path = NULL;
	info->w_path = NULL;
	info->e_path = NULL;
	info->map = NULL;
	info->map_x_size = 0;
	info->map_y_size = 0;
	info->hero.direction = -1;
}

void	parse_main(t_info *info, int argc, char **argv)
{
	if (argc != 2)
	{
		on_error("Invalid Argument Count");
	}
	else if (check_file_name(argv[1], ".cub"))
	{
		on_error("Invalid File Name");
	}
	init_info(info);
	format_check(info, argv[1]);
	map_parse(info, argv[1]);
	check_map(info);
}
