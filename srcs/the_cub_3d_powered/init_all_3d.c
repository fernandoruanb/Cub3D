/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_3d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 10:58:32 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/27 19:23:46 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_all_3d(t_game *game)
{
	game->center_win = game->heigth / 2;
	if (game->distance_x < 1.0)
		game->distance_x = 1.0;
	if (game->distance_x > 0)
	{
		game->wall_3d_height = (TILE_SIZE * game->heigth)
			/ game->distance_x;
		game->wall_3d_width = (TILE_SIZE * game->width)
			/ game->distance_x;
		if (game->wall_3d_height > game->heigth)
			game->wall_3d_height = game->heigth;
		game->draw_3d_center_s = game->center_win
			- (game->wall_3d_height / 2);
		game->draw_3d_center_e = game->center_win
			+ (game->wall_3d_height / 2);
	}
	else
	{
		game->wall_3d_height = 0;
		game->wall_3d_width = 0;
		game->draw_3d_center_s = 0;
		game->draw_3d_center_e = 0;
	}
}
