/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_entire_wall.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:05:55 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/08 18:50:19 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_entire_wall(t_game *game, int index)
{
	int	count;

	count = 0;
	while (game->true_game_map[index][count] != '\n'
		&& game->true_game_map[index][count] != '\0')
	{
		if (game->true_game_map[index][count] != '1'
			&& game->true_game_map[index][count] != ' '
			&& game->true_game_map[index][count] != '\t')
			return (ft_putendl_fd_0("Error: Map isn't closed", 2));
		count++;
	}
	return (1);
}
