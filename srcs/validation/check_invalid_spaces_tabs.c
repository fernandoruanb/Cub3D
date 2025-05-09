/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid_spaces_tabs.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 21:20:51 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/03 22:03:30 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_access(t_game *game, size_t i, size_t count, size_t len)
{
	int	index;

	index = 0;
	while (count < len)
	{
		if ((game->true_game_map[i][count] == ' '
			|| game->true_game_map[i][count] == '\t')
			&& game->true_game_map[i][count] != '\n'
			&& game->true_game_map[i][count] != '\0')
		{
			printf("obstacle: %c\n", game->true_game_map[i][count]);
			return (0);
		}
		count++;
	}
	return (1);
}

int	check_invalid_spaces_tabs(t_game *game)
{
	size_t	index;
	size_t	length;
	size_t	count;

	index = 0;
	while (game->true_game_map[index] != NULL)
	{
		count = 0;
		length = ft_strlen(game->true_game_map[index]);
		while (game->true_game_map[index][count]
			&& (game->true_game_map[index][count] == ' '
			|| game->true_game_map[index][count] == '\t'))
			count++;
		length = ft_strlen(game->true_game_map[index]);
		while (game->true_game_map[index][length - 2]
			&& (game->true_game_map[index][length - 2] == ' '
			|| game->true_game_map[index][length - 2] == '\t'))
			length--;
		if (!check_access(game, index, count, length))
			return (0);
		index++;
	}
	return (1);
}
