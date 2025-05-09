/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_valid_xpm.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 11:08:55 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/22 12:56:46 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_xpm(char *file_path)
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
			if (ft_strncmp(substr, ".xpm", 4) == 0)
			{
				free(substr);
				return (1);
			}
		}
		if (substr)
			free(substr);
		index++;
	}
	return (ft_putendl_fd_0("Error: file without .xpm file", 2));
}

int	check_is_valid_xpm(t_game *game)
{
	if (!check_xpm(game->no_texture))
		return (0);
	if (!check_xpm(game->so_texture))
		return (0);
	if (!check_xpm(game->we_texture))
		return (0);
	if (!check_xpm(game->ea_texture))
		return (0);
	return (1);
}
