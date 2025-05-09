/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_dda_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:48:56 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/02 18:52:38 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	calculate_sidedist(t_game *game, double px, double py)
{
	if (game->dda.stepx == -1)
	{
		game->dda.sidedistx = (px - game->dda.mapx)
			* game->dda.deltadistx;
	}
	else
	{
		game->dda.sidedistx = (game->dda.mapx + 1.0 - px)
			* game->dda.deltadistx;
	}
	if (game->dda.stepy == -1)
	{
		game->dda.sidedisty = (py - game->dda.mapy)
			* game->dda.deltadisty;
	}
	else
	{
		game->dda.sidedisty = (game->dda.mapy + 1.0 - py)
			* game->dda.deltadisty;
	}
}

void	init_dda_params(t_game *game, double px, double py)
{
	px = px / TILE_SIZE;
	py = py / TILE_SIZE;
	game->dda.mapx = (int)px;
	game->dda.mapy = (int)py;
	game->dda.deltadistx = fabs(1.0 / game->dda.raydirx);
	game->dda.deltadisty = fabs(1.0 / game->dda.raydiry);
	if (game->dda.raydirx < 0)
		game->dda.stepx = -1;
	else
		game->dda.stepx = 1;
	if (game->dda.raydiry < 0)
		game->dda.stepy = -1;
	else
		game->dda.stepy = 1;
	game->dda.hit = 0;
	calculate_sidedist(game, px, py);
}
