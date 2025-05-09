/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 15:40:14 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/01 14:30:12 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move_w(t_game *game)
{
	double	next_x;
	double	next_y;

	next_x = game->offset_x + game->dir_x * MOVE_SPEED;
	next_y = game->offset_y + game->dir_y * MOVE_SPEED;
	if (can_move(game, next_x, game->offset_y))
		game->offset_x = next_x;
	if (can_move(game, game->offset_x, next_y))
		game->offset_y = next_y;
}

void	move_s(t_game *game)
{
	double	next_x;
	double	next_y;

	next_x = game->offset_x - game->dir_x * MOVE_SPEED;
	next_y = game->offset_y - game->dir_y * MOVE_SPEED;
	if (can_move(game, next_x, game->offset_y))
		game->offset_x = next_x;
	if (can_move(game, game->offset_x, next_y))
		game->offset_y = next_y;
}

void	move_d(t_game *game)
{
	double	next_x;
	double	next_y;

	next_x = game->offset_x + game->plane_x * MOVE_SPEED;
	next_y = game->offset_y + game->plane_y * MOVE_SPEED;
	if (can_move(game, next_x, game->offset_y))
		game->offset_x = next_x;
	if (can_move(game, game->offset_x, next_y))
		game->offset_y = next_y;
}

void	move_a(t_game *game)
{
	double	next_x;
	double	next_y;

	next_x = game->offset_x - game->plane_x * MOVE_SPEED;
	next_y = game->offset_y - game->plane_y * MOVE_SPEED;
	if (can_move(game, next_x, game->offset_y))
		game->offset_x = next_x;
	if (can_move(game, game->offset_x, next_y))
		game->offset_y = next_y;
}
