/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 13:00:38 by jongmoon          #+#    #+#             */
/*   Updated: 2024/02/17 21:25:12 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

extern void	init_data_from_info(t_data *data, t_info *info);

t_map	make_map(int width, int height)
{
	t_map	map;
	int		i;

	map.width = width;
	map.height = height;
	map.data = (char **)malloc(sizeof(char *) * height);
	i = 0;
	while (i < height)
	{
		map.data[i] = (char *)malloc(sizeof(char) * width);
		i++;
	}
	return (map);
}

void	init_data(t_data *data, int argc, char **argv)
{
	t_info	info;

	parse_main(&info, argc, argv);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3D");
	data->img.ptr = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.ptr,
			&data->img.bits_per_pixel,
			&data->img.size_line,
			&data->img.endian);
	init_data_from_info(data, &info);
	free_info(&info);
	data->tick = 0;
	data->is_lr_pressed = 0;
	data->is_ws_pressed = 0;
	data->is_ad_pressed = 0;
	data->minimap = make_map(WIN_WIDTH / 5, WIN_HEIGHT / 5);
}

static void	free_map(t_map map)
{
	int	i;

	i = 0;
	while (i < map.height)
	{
		free(map.data[i]);
		i++;
	}
	free(map.data);
}

static void	free_textures(t_texture *textures)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < textures[i].height)
		{
			free(textures[i].data[j]);
			j++;
		}
		free(textures[i].data);
		i++;
	}
	free(textures);
}

void	teardown(t_data *data)
{
	free_map(data->map);
	free_textures(data->textures);
	free_map(data->minimap);
}
