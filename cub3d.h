/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:37:33 by jongmoon          #+#    #+#             */
/*   Updated: 2024/02/18 15:32:32 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "mlx.h"
# include "parse/parse.h"

# define WIN_WIDTH (800)
# define WIN_HEIGHT (800)

# define KEY_PRESS (2)
# define KEY_RELEASE (3)
# define MOTION_NOTIFY (6)
# define DESTROY_NOTIFY (17)

# define KEY_LEFT (123)
# define KEY_RIGHT (124)

# define KEY_W (13)
# define KEY_A (0)
# define KEY_S (1)
# define KEY_D (2)

# define KEY_ESCAPE (53)

enum e_dir
{
	NORTH,
	SOUTH,
	WEST,
	EAST
};

enum e_obj_type
{
	BACKGROUND,
	WALL,
	RAY,
	CHARACTER
};

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_texture
{
	int	**data;
	int	width;
	int	height;
}	t_texture;

typedef struct s_map
{
	char	**data;
	int		width;
	int		height;
}	t_map;

typedef struct s_color
{
	int	r;
	int	g;
	int	b;
}	t_color;

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_ivec2
{
	int	x;
	int	y;
}	t_ivec2;

typedef struct s_wall
{
	double		z;
	t_texture	texture;
	double		hit_x;
	double		length;
	int			top;
	int			bottom;
}	t_wall;

typedef struct s_data
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_texture	*textures;
	int			floor_color;
	int			ceiling_color;
	t_map		map;
	t_vec2		pos;
	t_vec2		cam;
	int			tick;
	int			is_lr_pressed;
	int			is_ws_pressed;
	int			is_ad_pressed;
	t_map		minimap;
}	t_data;

// init.c
void	init_data(t_data *data, int argc, char **argv);
void	teardown(t_data *data);

// texture.c
void	load_texture(t_data *data, enum e_dir dir, char *filename);

// color.c
int		color_from(int r, int g, int b);
int		lerp_color(int color0, int color1, double t);

// vec.c
t_vec2	make_vec2(double x, double y);
t_ivec2	make_ivec2(int x, int y);
t_vec2	translate(t_vec2 v0, t_vec2 v1, double t);
t_vec2	rotate(t_vec2 v0, double th);

// vec_utils.c
t_vec2	vec2_add(t_vec2 v0, t_vec2 v1);
t_vec2	vec2_mul(t_vec2 v, double k);
double	vec2_length(t_vec2 v);
t_vec2	vec2_normalize(t_vec2 v);

// math_utils.c
int		max(int a, int b);
int		min(int a, int b);
double	fmax(double a, double b);
double	fmin(double a, double b);
double	fclamp(double v, double lo, double hi);

// draw.c
void	pixel_put_on_image(t_data *data, int x, int y, int color);
void	draw_image(t_data *data);

// draw_column.c
void	draw_column(t_data *data, int x);

// raycast.c
double	raycast(t_data *data, t_vec2 ray, enum e_dir *hit_dir);
double	get_hit_x(t_data *data, t_vec2 displacement, enum e_dir hit_dir);

// raycast_utils.c
t_vec2	get_dist_over(t_vec2 ray);
t_vec2	get_initial_dist_from(t_vec2 pos, t_vec2 ray, t_vec2 dist_over);
t_ivec2	get_dda_dir(t_vec2 ray);
t_ivec2	dda_move(t_ivec2 pos, t_vec2 dist_from, t_ivec2 dda_dir);
t_vec2	dda_add(t_vec2 dist_from, t_vec2 dist_over);

// hooks.c
int		key_press_hook(int keycode, void *param);
int		key_release_hook(int keycode, void *param);
int		destroy_notify_hook(void *param);
int		loop_hook(void *param);

// move.c
t_vec2	move(t_map map, t_vec2 pos, t_vec2 dir, double t);

// draw_minimap.c
void	draw_minimap(t_data *data, const t_ivec2 offset, const int size);

// mouse_hook.c
void	init_cursor(t_data *data);
int		motion_notify_hook(int x, int y, void *param);

#endif
