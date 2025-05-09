/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_anything_null.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:14:33 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/23 09:06:03 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_anything_null(t_game *game)
{
	if (!game->no_texture)
		return (1);
	if (!game->so_texture)
		return (1);
	if (!game->we_texture)
		return (1);
	if (!game->ea_texture)
		return (1);
	if (!game->floor_colours)
		return (1);
	if (!game->ceiling_colours)
		return (1);
	if (!game->true_game_map)
		return (1);
	return (0);
}
