/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_no_texture.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:45:39 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/09 12:19:50 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_no_texture(t_game *game)
{
	int		index;
	char	**get_no;

	index = 0;
	while (game->maps[index] != NULL)
	{
		if (find_texture(game->maps[index], "NO ", 3))
		{
			if (find_another(game->maps, index, "NO "))
				return (0);
			get_no = ft_split(game->maps[index], ' ');
			remove_spaces_and_tabs(&get_no);
			if (!check_split_length(get_no))
				return (free_dynamic_texture(get_no));
			game->no_texture = ft_strdup(get_no[1]);
			if (!game->no_texture)
			{
				free_splits(NULL, get_no, NULL, NULL);
				return (0);
			}
			free_splits(NULL, get_no, NULL, NULL);
		}
		index++;
	}
	return (1);
}
