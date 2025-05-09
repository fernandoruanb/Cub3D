/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:26:35 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/07 22:57:05 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	free_true_game_map(t_game *game)
{
	int	index;

	index = 0;
	while (game->true_game_map[index] != NULL)
	{
		free(game->true_game_map[index]);
		index++;
	}
	free(game->true_game_map);
	game->true_game_map = NULL;
}

static void	free_map(t_game *game)
{
	int	index;

	index = 0;
	while (game->maps[index] != NULL)
	{
		free(game->maps[index]);
		index++;
	}
	free(game->maps);
}

static void	clear_all_textures(t_game *game)
{
	if (game->no_texture != NULL)
		free(game->no_texture);
	if (game->so_texture != NULL)
		free(game->so_texture);
	if (game->we_texture != NULL)
		free(game->we_texture);
	if (game->ea_texture != NULL)
		free(game->ea_texture);
	if (game->floor_colours)
		free(game->floor_colours);
	if (game->ceiling_colours)
		free(game->ceiling_colours);
	game->no_texture = NULL;
	game->so_texture = NULL;
	game->we_texture = NULL;
	game->ea_texture = NULL;
	game->floor_colours = NULL;
	game->ceiling_colours = NULL;
}

static void	clear_all_images(t_game *game)
{
	if (game->ea_img)
		mlx_destroy_image(game->mlx.mlx_ptr, game->ea_img);
	if (game->no_img)
		mlx_destroy_image(game->mlx.mlx_ptr, game->no_img);
	if (game->so_img)
		mlx_destroy_image(game->mlx.mlx_ptr, game->so_img);
	if (game->we_img)
		mlx_destroy_image(game->mlx.mlx_ptr, game->we_img);
	if (game->mouse.target)
		mlx_destroy_image(game->mlx.mlx_ptr, game->mouse.target);
	game->ea_img = NULL;
	game->no_img = NULL;
	game->so_img = NULL;
	game->we_img = NULL;
}

int	free_game(t_game *game)
{
	if (!game)
		return (1);
	if (game->maps)
		free_map(game);
	clear_all_images(game);
	clear_all_textures(game);
	if (game->true_game_map)
		free_true_game_map(game);
	if (game->rrggbb_floor)
		free(game->rrggbb_floor);
	if (game->rrggbb_ceiling)
		free(game->rrggbb_ceiling);
	game->rrggbb_floor = NULL;
	game->rrggbb_ceiling = NULL;
	return (0);
}
