/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_invalid_access.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 18:21:24 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/22 12:55:51 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_invalid_access(t_game *game)
{
	int	index;
	int	count;

	index = 1;
	while (game->true_game_map[index] != NULL)
	{
		count = 0;
		while (game->true_game_map[index][count] != '\n' &&
			game->true_game_map[index][count] != '\0')
		{
			if (game->true_game_map[index][count] == '0'
				&& game->true_game_map[index - 1][count] == ' ')
				return (ft_putendl_fd_0("Error: HOLE!", 2));
			count++;
		}
		index++;
	}
	return (1);
}
