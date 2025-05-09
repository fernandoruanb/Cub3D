/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_true_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:39:09 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/03 19:22:57 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_special_chars(t_game *game)
{
	int	index;

	index = 0;
	while (game->true_game_map[index] != NULL)
	{
		if (game->true_game_map[index][0]
			&& (game->true_game_map[index][0] == '\n'
			|| game->true_game_map[index][0] == '\v'
			|| game->true_game_map[index][0] == '\f'
			|| game->true_game_map[index][0] == '\r'
			|| game->true_game_map[index][0] == '\b'
			|| game->true_game_map[index][0] == '\a'
			|| game->true_game_map[index][0] == '\\'))
			return (0);
		index++;
	}
	return (1);
}

static int	surrounded_by_walls(t_game *game)
{
	size_t	index;
	size_t	lines;

	index = 0;
	lines = get_all_lines(game);
	while (game->true_game_map[index] != NULL)
	{
		if (index == 0 || index == lines - 1)
		{
			if (!check_entire_wall(game, index))
				return (0);
		}
		else
		{
			if (!check_first_last_wall(game, index))
				return (0);
		}
		index++;
	}
	return (1);
}

int	check_true_map(t_game *game)
{
	if (!check_special_chars(game))
		return (ft_putendl_fd_0("Error: \\n,\\t,\\ found on map", 2));
	if (!surrounded_by_walls(game))
		return (0);
	return (1);
}
