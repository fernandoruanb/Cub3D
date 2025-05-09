/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 19:13:47 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/22 12:53:22 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_content(const char *filename)
{
	int		fd;
	char	buffer[1024];
	ssize_t	bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (0);
	bytes_read = read(fd, buffer, sizeof(buffer));
	if (bytes_read == -1 || bytes_read == 0)
	{
		close(fd);
		return (0);
	}
	close(fd);
	return (1);
}

int	check_cub(const char *filename)
{
	char	*check_str;
	char	*substr;
	size_t	length;
	size_t	index;

	check_str = ".cub";
	length = ft_strlen(filename);
	index = 0;
	while (filename[index] != '\0')
	{
		if (filename[index] == '.')
		{
			substr = ft_substr(filename, index, length - index);
			if (ft_strcmp(substr, check_str) == 0)
			{
				free(substr);
				return (check_content(filename));
			}
			free(substr);
		}
		index++;
	}
	return (ft_putendl_fd_0("Error: .cub file only", 2));
}
