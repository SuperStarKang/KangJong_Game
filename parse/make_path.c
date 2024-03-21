/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jongmoon <jongmoon@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 12:54:33 by kangmlee          #+#    #+#             */
/*   Updated: 2024/02/18 13:58:42 by jongmoon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse.h"

void	make_path(char **ppath, char *path, t_check *check)
{
	if (check->start_lineno != -1)
	{
		on_error("Mixed Order");
	}
	else if (path[0] == 0)
	{
		on_error("Invalid Path");
	}
	else if (*ppath != NULL)
	{
		on_error("Invalid Element Count");
	}
	*ppath = ft_strtrim(path, " ");
}
