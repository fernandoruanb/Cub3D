/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_fov.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/24 21:07:14 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/27 17:30:25 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	get_dir_x_y(t_game *game, double calc, double calc2)
{
	game->dir_x_c = calc - game->px_start;
	game->dir_y_c = calc2 - game->py_start;
}

static void	new_position_px_py(t_game *game, double *px, double *py)
{
	*px = (game->width / 2) + game->offset_x;
	*py = (game->heigth / 2) + game->offset_y;
	game->px_start = *px;
	game->py_start = *py;
}

static void	draw_new_radius_right(t_game *game)
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
		px += game->dir_right_x;
		py += game->dir_right_y;
	}
	get_dir_x_y(game, game->dir_right_x, game->dir_right_y);
	get_distance(game, 3);
}

static void	draw_new_radius_left(t_game *game)
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
		px += game->dir_left_x;
		py += game->dir_left_y;
	}
	get_dir_x_y(game, game->dir_left_x, game->dir_left_y);
	get_distance(game, 2);
}

void	draw_fov(t_game *game)
{
	game->angle_left = game->angle - VISUAL_CAMP;
	game->angle_right = game->angle + VISUAL_CAMP;
	game->dir_left_x = cos(game->angle_left);
	game->dir_left_y = sin(game->angle_left);
	game->dir_right_x = cos(game->angle_right);
	game->dir_right_y = sin(game->angle_right);
	draw_new_radius_left(game);
	draw_new_radius_right(game);
}
