/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_first_last_wall.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:35:31 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/03 19:27:32 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_first_last_wall(t_game *game, int index)
{
	size_t	length;
	size_t	count;

	count = 0;
	length = ft_strlen(game->true_game_map[index]);
	while (game->true_game_map[index][count] == ' '
		|| game->true_game_map[index][count] == '\t')
		count++;
	if (game->true_game_map[index][count] != '1')
		return (ft_putendl_fd_0("Error: map isn't closed", 2));
	if (game->true_game_map[index][length - 2] != '1')
	{
		--length;
		while (game->true_game_map[index][length - 2]
			&& (game->true_game_map[index][length - 2] == ' '
			|| game->true_game_map[index][length - 2] == '\t'))
			length--;
		if (game->true_game_map[index][length - 2] != '1')
			return (ft_putendl_fd_0("Error: map isn't closed", 2));
	}
	return (1);
}
