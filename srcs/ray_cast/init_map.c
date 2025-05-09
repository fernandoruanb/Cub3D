/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 12:23:38 by jopereir          #+#    #+#             */
/*   Updated: 2025/05/05 18:42:14 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_angle(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

static void	set_angle(char dir, t_player *player)
{
	t_angle	angle[4];
	int		i;

	angle[0].dir = 'N';
	angle[0].angle = 90;
	angle[1].dir = 'S';
	angle[1].angle = 270;
	angle[2].dir = 'E';
	angle[2].angle = 0;
	angle[3].dir = 'W';
	angle[3].angle = 180;
	i = -1;
	while (++i < 4)
		if (angle[i].dir == dir)
			player->angle = angle[i].angle;
}

static void	init_player(t_player *player, t_game *game)
{
	int	i;
	int	j;

	player->x = game->player_x;
	player->y = game->player_y;
	i = 0;
	while (game->true_game_map[i])
	{
		j = -1;
		while (game->true_game_map[i][++j])
		{
			if (get_angle(game->true_game_map[i][j]))
			{
				set_angle(game->true_game_map[i][j], player);
				return ;
			}
		}
		i++;
	}
	player->angle = 90;
}

void	init_map(t_map *map, t_game *game)
{
	map->map = &game->true_game_map;
	init_player(&map->player, game);
}
