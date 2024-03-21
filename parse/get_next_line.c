/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kangmlee <kangmlee@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:38:03 by kangmlee          #+#    #+#             */
/*   Updated: 2024/01/24 16:15:09 by kangmlee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_next(char *backup)
{
	char	*next;
	int		newline;
	int		i;

	newline = has_newline(backup);
	if (newline == -1)
		return (backup);
	next = (char *)malloc((ft_strlen(backup) - newline) * sizeof(char));
	if (!(next))
		return (ft_free(&backup));
	i = 0;
	newline++;
	while (backup[newline])
	{
		next[i] = backup[newline];
		i++;
		newline++;
	}
	next[i] = '\0';
	backup = ft_free(&backup);
	return (next);
}

static char	*ft_make_line(char *backup)
{
	char	*line;
	int		i;

	i = 0;
	while (backup[i] && backup[i] != '\n')
		i++;
	line = (char *)malloc((i + 1) * sizeof(char));
	if (!(line))
		return (0);
	i = 0;
	while (backup[i] && backup[i] != '\n')
	{
		line[i] = backup[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*ft_read_file(int fd, char *backup)
{
	char	buffer[BUFFER_SIZE + 1];
	int		read_size;

	if (!(backup))
	{
		backup = (char *)malloc(1 * sizeof(char));
		if (!(backup))
			return (0);
		backup[0] = '\0';
	}
	while (has_newline(backup) == -1)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size == 0)
			break ;
		if (read_size == -1)
			return (ft_free(&backup));
		buffer[read_size] = '\0';
		backup = ft_strjoin(backup, buffer);
		if (!backup)
			return (0);
	}
	return (backup);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	backup = ft_read_file(fd, backup);
	if (!(backup) || !(backup[0]))
		return (ft_free(&backup));
	line = ft_make_line(backup);
	if (!line)
		return (ft_free(&backup));
	if (has_newline(backup) == -1)
	{
		backup = ft_free(&backup);
		return (line);
	}
	backup = ft_next(backup);
	return (line);
}
