/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_angle_dir_x_y.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 16:56:52 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/07 14:45:46 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	update_angle_dir_x_y(t_game *game, int keycode)
{
	if (keycode == 65361)
		game->angle -= ROTATION_SPEED;
	else if (keycode == 65363)
		game->angle += ROTATION_SPEED;
	if (game->angle < 0)
		game->angle += 2 * M_PI;
	if (game->angle >= 2 * M_PI)
		game->angle -= 2 * M_PI;
	game->dir_x = cos(game->angle);
	game->dir_y = sin(game->angle);
	get_plane_x_y(game);
}
