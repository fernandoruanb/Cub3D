/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_distance.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 16:47:26 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/27 11:30:13 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	get_distance(t_game *game, int flag)
{
	if (flag == 1)
	{
		game->distance = sqrt((game->dir_x_c * game->dir_x_c)
				+ (game->dir_y_c * game->dir_y_c));
	}
	if (flag == 2)
	{
		game->distance_l = sqrt((game->dir_x_c * game->dir_x_c)
				+ (game->dir_y_c * game->dir_y_c));
	}
	if (flag == 3)
	{
		game->distance_r = sqrt((game->dir_x_c * game->dir_x_c)
				+ (game->dir_y_c * game->dir_y_c));
	}
	if (flag == 4)
	{
		game->distance_x = sqrt((game->dir_x_c * game->dir_x_c)
				+ (game->dir_y_c * game->dir_y_c));
		game->distance_x = game->distance_x * cos(game->angle_k - game->angle);
	}
}
