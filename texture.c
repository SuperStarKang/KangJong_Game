/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:38:02 by jongmoon          #+#    #+#             */
/*   Updated: 2024/02/17 21:22:45 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static t_img	load_xpm_image(t_data *data, char *filename, t_texture *texture)
{
	t_img	img;

	img.ptr = mlx_xpm_file_to_image(data->mlx, filename, &texture->width,
			&texture->height);
	if (img.ptr == NULL)
	{
		on_error("Wrong Texture");
	}
	img.addr = mlx_get_data_addr(img.ptr, &img.bits_per_pixel, &img.size_line,
			&img.endian);
	return (img);
}

static int	pixel_get_on_image(t_img *img, int x, int y)
{
	int		offset;
	char	*dest;

	offset = y * img->size_line + x * (img->bits_per_pixel / 8);
	dest = img->addr + offset;
	return (*(unsigned int *)dest);
}

void	load_texture(t_data *data, enum e_dir dir, char *filename)
{
	t_img		img;
	t_texture	texture;
	int			y;
	int			x;

	img = load_xpm_image(data, filename, &texture);
	texture.data = (int **)malloc(sizeof(int *) * texture.height);
	y = 0;
	while (y < texture.height)
	{
		texture.data[y] = (int *)malloc(sizeof(int) * texture.width);
		x = 0;
		while (x < texture.width)
		{
			texture.data[y][x] = pixel_get_on_image(&img, x, y);
			x++;
		}
		y++;
	}
	data->textures[dir] = texture;
	mlx_destroy_image(data->mlx, img.ptr);
}
