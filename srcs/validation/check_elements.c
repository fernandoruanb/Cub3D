/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_elements.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 14:49:51 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/03 21:59:31 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_each_element(char c, t_game *game, int y, int x)
{
	char	*elements;

	elements = "01NSEW";
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		game->players++;
		if (game->players > 1)
			return (ft_putendl_fd_0("Error: too many players", 2));
		game->player_x = x;
		game->player_y = y;
	}
	if (!ft_strchr(elements, c) && c != ' ' && c != '\t')
		return (ft_putendl_fd_0("Error: invalid element on map", 2));
	return (1);
}

int	check_elements(t_game *game)
{
	int		index;
	int		count;
	char	c;

	index = 0;
	while (game->true_game_map[index] != NULL)
	{
		count = 0;
		while (game->true_game_map[index][count]
			&& (game->true_game_map[index][count] == ' '
			|| game->true_game_map[index][count] == '\t'))
			count++;
		while (game->true_game_map[index][count] != '\n'
			&& game->true_game_map[index][count] != '\0')
		{
			c = game->true_game_map[index][count];
			if (!check_each_element(c, game, index, count))
				return (0);
			count++;
		}
		index++;
	}
	if (game->players != 1)
		return (ft_putendl_fd_0("Error: where is the player?", 2));
	return (1);
}
