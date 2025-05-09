/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:03:04 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/02 18:46:11 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_ray(t_game *game, int x)
{
	double	camera_x;

	camera_x = 2.0 * x / game->width - 1.0;
	game->dda.raydirx = game->rays.dirx + game->rays.planex * camera_x;
	game->dda.raydiry = game->rays.diry + game->rays.planey * camera_x;
}
