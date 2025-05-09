/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_camera_plane.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 17:35:03 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/02 18:45:09 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_camera_plane(t_game *game)
{
	game->rays.dirx = cos(game->angle);
	game->rays.diry = sin(game->angle);
	game->rays.planex = -game->rays.diry * VISUAL_CAMP;
	game->rays.planey = game->rays.dirx * VISUAL_CAMP;
}
