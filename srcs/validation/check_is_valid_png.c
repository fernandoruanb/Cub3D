/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_valid_png.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 11:08:55 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/21 12:59:32 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_png(char *file_path)
{
	size_t	index;
	char	*substr;
	size_t	length;

	index = 0;
	length = ft_strlen(file_path);
	while (file_path[index] != '\0')
	{
		substr = NULL;
		if (file_path[index] == '.')
		{
			substr = ft_substr(file_path, index, length - index);
			if (ft_strncmp(substr, ".png", 4) == 0)
			{
				free(substr);
				return (1);
			}
		}
		if (substr)
			free(substr);
		index++;
	}
	return (ft_putendl_fd_0("File without .png file", 2));
}

int	check_is_valid_png(t_game *game)
{
	if (!check_png(game->no_texture))
		return (0);
	if (!check_png(game->so_texture))
		return (0);
	if (!check_png(game->we_texture))
		return (0);
	if (!check_png(game->ea_texture))
		return (0);
	return (1);
}
