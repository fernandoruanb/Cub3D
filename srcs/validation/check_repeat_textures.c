/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_repeat_textures.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:45:54 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/22 12:57:02 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_repeat_textures(t_game *game)
{
	int	index;

	index = 0;
	while (game->maps[index] != NULL)
	{
		if (ft_strncmp(game->maps[index], "NO", 2) == 0)
			game->no_texture_index++;
		if (ft_strncmp(game->maps[index], "SO", 2) == 0)
			game->so_texture_index++;
		if (ft_strncmp(game->maps[index], "WE", 2) == 0)
			game->we_texture_index++;
		if (ft_strncmp(game->maps[index], "EA", 2) == 0)
			game->ea_texture_index++;
		if (ft_strncmp(game->maps[index], "F", 1) == 0)
			game->floor_colours_index++;
		if (ft_strncmp(game->maps[index], "C", 1) == 0)
			game->ceiling_colours_index++;
		index++;
	}
	if (game->no_texture_index > 1 || game->so_texture_index > 1
		|| game->we_texture_index > 1 || game->ea_texture_index > 1
		|| game->floor_colours_index > 1
		|| game->ceiling_colours_index > 1)
		return (ft_putendl_fd_0("Error: Textures repeated", 2));
	return (1);
}
