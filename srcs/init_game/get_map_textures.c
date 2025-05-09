/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 09:39:48 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/21 18:05:04 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_map_textures(t_game *game)
{
	if (!check_repeat_textures(game))
		return (0);
	if (!get_no_texture(game))
		return (0);
	if (!get_so_texture(game))
		return (0);
	if (!get_we_texture(game))
		return (0);
	if (!get_ea_texture(game))
		return (0);
	if (!get_floor_colours(game))
		return (0);
	if (!get_ceiling_colours(game))
		return (0);
	if (!get_true_map(game))
		return (0);
	return (1);
}
