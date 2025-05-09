/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 20:21:08 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/06 19:20:42 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	update_angle(t_game *game)
{
	if (game->player_eye == 'S')
		game->angle = 90 * (M_PI / 180.0);
	else if (game->player_eye == 'N')
		game->angle = 270 * (M_PI / 180.0);
	else if (game->player_eye == 'W')
		game->angle = 180 * (M_PI / 180.0);
	else if (game->player_eye == 'E')
		game->angle = 0;
}

static void	set_player_eye_direction(t_game *game)
{
	game->player_eye = game->true_game_map[game->player_y][game->player_x];
	if (game->player_eye == 'S')
	{
		game->dir_x = 0;
		game->dir_y = 1;
	}
	else if (game->player_eye == 'N')
	{
		game->dir_x = 0;
		game->dir_y = -1;
	}
	else if (game->player_eye == 'W')
	{
		game->dir_x = -1;
		game->dir_y = 0;
	}
	else if (game->player_eye == 'E')
	{
		game->dir_x = 1;
		game->dir_y = 0;
	}
	update_angle(game);
}

static void	get_offset_x_y(t_game *game)
{
	game->offset_x = game->player_x * TILE_SIZE
		+ TILE_SIZE / 2 - (game->width / 2);
	game->offset_y = game->player_y * TILE_SIZE
		+ TILE_SIZE / 2 - (game->heigth / 2);
}

int	init_game(const char *filename, t_game *game)
{
	init_all_things(game);
	game->maps = get_map(filename);
	game->mlx.mlx_ptr = mlx_init();
	if (!game->mlx.mlx_ptr)
		return (drawstr("Error: mlx error\n", 2, 1));
	if (!game->maps || !check_security_on_map(game)
		|| !get_map_textures(game))
		return (0);
	if (!is_valid_map(game))
		return (0);
	if (!check_and_set_images(game))
		return (ft_putendl_fd_0("Error: invalid images", 2));
	if (!get_width_heigth(game))
		return (0);
	if (!rgb_to_rrggbb(game))
		return (ft_putendl_fd_0("Error: converting to RRGGBB", 2));
	if (!game->rrggbb_floor || !game->rrggbb_ceiling)
		return (ft_putendl_fd_0("Error: hole on rrggbb", 2));
	game->max_col = game->heigth / TILE_SIZE;
	game->max_row = game->width / TILE_SIZE;
	set_player_eye_direction(game);
	get_offset_x_y(game);
	get_plane_x_y(game);
	init_map(&game->map, game);
	return (1);
}
