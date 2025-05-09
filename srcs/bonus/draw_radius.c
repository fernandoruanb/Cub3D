/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_radius.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 11:03:01 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/27 17:30:10 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	get_dir_x_y(t_game *game)
{
	game->dir_x_c = game->dir_x - game->px_start;
	game->dir_y_c = game->dir_x - game->py_start;
}

static void	new_position_px_py(t_game *game, double *px, double *py)
{
	*px = (game->width / 2) + game->offset_x;
	*py = (game->heigth / 2) + game->offset_y;
	game->px_start = *px;
	game->py_start = *py;
}

void	draw_radius(t_game *game)
{
	double	px;
	int		map_x;
	int		map_y;
	double	py;

	new_position_px_py(game, &px, &py);
	while (1)
	{
		map_x = px / TILE_SIZE;
		map_y = py / TILE_SIZE;
		if (px < 0 || py < 0
			|| map_y >= game->heigth / TILE_SIZE
			|| map_x >= (int)ft_strlen(game->true_game_map[map_y]))
			break ;
		if (game->true_game_map[map_y][map_x] == '1'
			|| game->true_game_map[map_y][map_x] == ' ')
			break ;
		mlx_pixel_put(game->mlx.mlx_ptr, game->mlx.win,
			(px - game->offset_x) * MINIMAP_SCALE,
			(py - game->offset_y) * MINIMAP_SCALE, COLOUR_RADIUS);
		px += game->dir_x;
		py += game->dir_y;
	}
	get_dir_x_y(game);
	get_distance(game, 1);
}
