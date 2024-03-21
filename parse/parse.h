/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 15:32:22 by kangmlee          #+#    #+#             */
/*   Updated: 2024/02/18 13:17:59 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include "libft.h"
# include "get_next_line.h"

# include "cub3d.h"

typedef struct s_check {
	int	f_color;
	int	c_color;
	int	start_lineno;
	int	end_lineno;
}	t_check;

typedef struct s_hero {
	int	x;
	int	y;
	int	direction;
}	t_hero;

typedef struct s_info {
	int		map_location;
	char	*n_path;
	char	*s_path;
	char	*w_path;
	char	*e_path;
	int		f_color[3];
	int		c_color[3];
	char	**map;
	int		map_x_size;
	int		map_y_size;
	t_hero	hero;
}	t_info;

// map_parse
void	map_parse(t_info *info, char *file);

// make_path
void	make_path(char **ppath, char *path, t_check *check);

// make_color
void	make_color(int *colors, char *color_str, int *pcheck, t_check *check);

// texture_parse
void	format_check(t_info *info, char *file);

// check
int		check_map(t_info *info);
int		check_file_name(char *file, char *ber);

// utils
void	on_error(char *msg);

// free
void	free_info(t_info *info);

// parse
void	parse_main(t_info *info, int argc, char **argv);

#endif