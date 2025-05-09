/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 19:32:43 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/24 15:14:28 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	show_true_game_map(t_game *game)
{
	int	index;

	index = 0;
	while (game->true_game_map[index] != NULL)
	{
		ft_printf("[%i]: %s\n", index, game->true_game_map[index]);
		index++;
	}
}

void	show_textures(t_game *game)
{
	if (game->no_texture)
		ft_printf("NO:%s\n", game->no_texture);
	if (game->so_texture)
		ft_printf("SO:%s\n", game->so_texture);
	if (game->we_texture)
		ft_printf("WE:%s\n", game->we_texture);
	if (game->ea_texture)
		ft_printf("EA:%s\n", game->ea_texture);
	if (game->floor_colours)
		ft_printf("F:%s\n", game->floor_colours);
	if (game->ceiling_colours)
		ft_printf("C:%s\n", game->ceiling_colours);
	ft_printf("player_x: %d\n\n", game->player_x);
	ft_printf("player_y: %d\n\n", game->player_y);
	ft_printf("Width Window: %d\n\n", game->width);
	ft_printf("Heigth Window: %d\n\n", game->heigth);
	ft_printf("Width Map: %d\n\n", game->width_map);
	ft_printf("Heigth Map: %d\n\n", game->heigth_map);
	ft_printf("rrggbb_floor: %s\n\n", game->rrggbb_floor);
	ft_printf("rrggbb_ceiling: %s\n\n", game->rrggbb_ceiling);
	if (game->true_game_map)
		show_true_game_map(game);
}
