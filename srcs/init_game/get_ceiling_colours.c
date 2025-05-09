/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ceiling_colours.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:45:39 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/09 12:20:23 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_ceiling_colours(t_game *game)
{
	int		index;
	char	**get_c_colours;

	index = 0;
	while (game->maps[index] != NULL)
	{
		if (find_texture(game->maps[index], "C ", 2))
		{
			if (find_another(game->maps, index, "C "))
				return (0);
			get_c_colours = ft_split(game->maps[index], ' ');
			remove_spaces_and_tabs(&get_c_colours);
			if (!check_split_length(get_c_colours))
				return (free_dynamic_texture(get_c_colours));
			game->ceiling_colours = ft_strdup(get_c_colours[1]);
			if (!game->ceiling_colours)
			{
				free_splits(NULL, get_c_colours, NULL, NULL);
				return (0);
			}
			free_splits(NULL, get_c_colours, NULL, NULL);
		}
		index++;
	}
	return (1);
}
