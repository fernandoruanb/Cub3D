/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_so_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:45:39 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/09 12:20:04 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_so_texture(t_game *game)
{
	int		index;
	char	**get_so;

	index = 0;
	while (game->maps[index] != NULL)
	{
		if (find_texture(game->maps[index], "SO ", 3))
		{
			if (find_another(game->maps, index, "SO "))
				return (0);
			get_so = ft_split(game->maps[index], ' ');
			remove_spaces_and_tabs(&get_so);
			if (!check_split_length(get_so))
				return (free_dynamic_texture(get_so));
			game->so_texture = ft_strdup(get_so[1]);
			if (!game->so_texture)
			{
				free_splits(NULL, get_so, NULL, NULL);
				return (0);
			}
			free_splits(NULL, get_so, NULL, NULL);
		}
		index++;
	}
	return (1);
}
