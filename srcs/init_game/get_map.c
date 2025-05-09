/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:40:57 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/23 18:43:38 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_how_many_lines(const char *filename)
{
	char	*line;
	int		lines;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd_0("Error: unable to open file", 2));
	lines = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		lines++;
		free(line);
		line = get_next_line(fd);
	}
	free(get_next_line(fd));
	close(fd);
	return (lines);
}

static char	**clear_map(char **map, int index, int fd)
{
	int	count;

	count = 0;
	--index;
	while (count < index)
	{
		free(map[index]);
		count++;
	}
	free(map);
	map = NULL;
	close(fd);
	return (NULL);
}

static char	**get_the_map(const char *filename, int lines)
{
	char	**map;
	char	*line;
	int		index;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd_n("Error: failed to open file", 2));
	map = (char **)malloc((lines + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	line = get_next_line(fd);
	index = 0;
	while (line != NULL)
	{
		map[index] = ft_strdup(line);
		if (!map[index])
			return (clear_map(map, index, fd));
		free(line);
		line = get_next_line(fd);
		index++;
	}
	map[index] = NULL;
	close(fd);
	return (map);
}

char	**get_map(const char *filename)
{
	int		lines;
	char	**map;

	lines = get_how_many_lines(filename);
	map = get_the_map(filename, lines);
	return (map);
}
