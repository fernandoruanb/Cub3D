/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda_loop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:17:14 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/02 18:50:30 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_security(t_game *game)
{
	if (game->dda.mapx < 0
		|| game->dda.mapx >= game->width_map
		|| game->dda.mapy < 0
		|| game->dda.mapy >= game->heigth_map)
	{
		game->dda.hit = 1;
		return (1);
	}
	return (0);
}

void	dda_loop(t_game *game)
{
	while (game->dda.hit == 0)
	{
		if (game->dda.sidedistx < game->dda.sidedisty)
		{
			game->dda.sidedistx += game->dda.deltadistx;
			game->dda.mapx += game->dda.stepx;
			game->dda.side = 0;
		}
		else
		{
			game->dda.sidedisty += game->dda.deltadisty;
			game->dda.mapy += game->dda.stepy;
			game->dda.side = 1;
		}
		if (check_security(game))
			break ;
		if (game->true_game_map[game->dda.mapy][game->dda.mapx] == '1'
			|| game->true_game_map[game->dda.mapy][game->dda.mapx] == ' ')
			game->dda.hit = 1;
	}
}
