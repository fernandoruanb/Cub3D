/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ea_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:45:39 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/09 12:19:56 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_ea_texture(t_game *game)
{
	int		index;
	char	**get_ea;

	index = 0;
	while (game->maps[index] != NULL)
	{
		if (find_texture(game->maps[index], "EA ", 2))
		{
			if (find_another(game->maps, index, "EA "))
				return (0);
			get_ea = ft_split(game->maps[index], ' ');
			remove_spaces_and_tabs(&get_ea);
			if (!check_split_length(get_ea))
				return (free_dynamic_texture(get_ea));
			game->ea_texture = ft_strdup(get_ea[1]);
			if (!game->ea_texture)
			{
				free_splits(NULL, get_ea, NULL, NULL);
				return (0);
			}
			free_splits(NULL, get_ea, NULL, NULL);
		}
		index++;
	}
	return (1);
}
