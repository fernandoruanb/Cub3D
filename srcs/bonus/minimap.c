/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 10:04:13 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/04 17:16:53 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	show_the_art_to_godness(t_game *game, int s_y, int s_x, int c)
{
	int	y;
	int	x;
	int	dx;
	int	dy;

	dx = game->origin_x + (int)((s_y * TILE_SIZE - game->world_x)
			* MINIMAP_SCALE);
	dy = game->origin_y + (int)((s_x * TILE_SIZE - game->world_y)
			* MINIMAP_SCALE);
	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			mlx_pixel_put(game->mlx.mlx_ptr, game->mlx.win,
				(dx + x) * MINIMAP_SCALE, (dy + y)
				* MINIMAP_SCALE, c);
			x++;
		}
		y++;
	}
}

static void	init_player_location(t_game *game)
{
	game->center_y = game->origin_x
		+ (game->minimap_w * TILE_SIZE) / 2;
	game->center_x = game->origin_y
		+ (game->minimap_h * TILE_SIZE) / 2;
	game->player_size = TILE_SIZE / 4 * MINIMAP_SCALE;
	game->start_x = game->center_x - game->player_size / 2;
	game->start_y = game->center_y - game->player_size / 2;
}

static void	draw_the_player(t_game *game)
{
	int	new_player_x_location;
	int	new_player_y_location;
	int	x;
	int	y;

	init_player_location(game);
	new_player_x_location = ((game->width / 2)
			- (TILE_SIZE / 4)) * MINIMAP_SCALE;
	new_player_y_location = ((game->heigth / 2)
			- (TILE_SIZE / 4)) * MINIMAP_SCALE;
	y = 0;
	while (y < TILE_SIZE / 4)
	{
		x = 0;
		while (x < TILE_SIZE / 4)
		{
			mlx_pixel_put(game->mlx.mlx_ptr, game->mlx.win,
				x + new_player_x_location, y
				+ new_player_y_location, COLOUR_PLAYER);
			x++;
		}
		y++;
	}
	draw_radius(game);
	draw_fov(game);
}

static void	init_location_variables(t_game *game, int *index)
{
	*index = 0;
	game->minimap_w = game->width_map * TILE_SIZE;
	game->minimap_h = game->heigth_map * TILE_SIZE;
	game->origin_x = game->width - game->minimap_w * MINIMAP_SCALE;
	game->origin_y = 0;
	game->world_x = game->player_x * TILE_SIZE - (game->minimap_w / 2.0);
	game->world_y = game->player_y * TILE_SIZE - (game->minimap_h / 2.0);
}

void	minimap(t_game *game)
{
	int		index;
	int		count;
	int		color;
	char	c;

	init_location_variables(game, &index);
	while (game->true_game_map[index] != NULL)
	{
		count = 0;
		while (game->true_game_map[index][count] != '\0')
		{
			c = game->true_game_map[index][count];
			if (c == '1')
				color = COLOUR_DEFAULT;
			else if (c == '0' || c == 'N' || c == 'W' || c == 'E'
				|| c == 'S')
				color = ft_atoi_base(game->rrggbb_floor + 2, 16);
			if (c == '0' || c == '1' || c == 'N'
				|| c == 'W' || c == 'E' || c == 'S')
				show_the_art_to_godness(game, index, count, color);
			count++;
		}
		index++;
	}
	draw_the_player(game);
}
