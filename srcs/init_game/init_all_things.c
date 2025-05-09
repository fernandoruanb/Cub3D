/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_all_things.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 22:54:02 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/05 20:24:54 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	set_more_more_things(t_game *game)
{
	game->no.addr = NULL;
	game->so.addr = NULL;
	game->we.addr = NULL;
	game->ea.addr = NULL;
	game->pitch = 0;
}

static void	set_more_things(t_game *game)
{
	game->offset_x = 0;
	game->offset_y = 0;
	game->min_col = 0;
	game->min_row = 0;
	game->max_col = 0;
	game->min_col = 0;
	game->dir_x = 1;
	game->dir_y = 0;
	game->width_map = 0;
	game->heigth_map = 0;
	game->angle = 0;
	game->angle_left = 0;
	game->angle_right = 0;
	game->dir_left_x = 0;
	game->dir_left_y = 0;
	game->dir_right_x = 0;
	game->dir_right_y = 0;
	game->ea_img = NULL;
	game->so_img = NULL;
	game->no_img = NULL;
	game->we_img = NULL;
	game->wall_3d_height = 0;
	game->wall_3d_width = 0;
	game->screen_w = 0;
	set_more_more_things(game);
}

static void	init_mouse(t_game *game)
{
	game->mouse.x = 0;
	game->mouse.y = 0;
	game->mouse.prev_x = -1;
	game->mouse.prev_y = -1;
}

void	init_all_things(t_game *game)
{
	game->mlx.mlx_ptr = NULL;
	game->mlx.win = NULL;
	game->players = 0;
	game->invalid_map = 0;
	game->width = -1;
	game->heigth = -1;
	game->rrggbb_floor = NULL;
	game->rrggbb_ceiling = NULL;
	game->maps = NULL;
	game->no_texture = NULL;
	game->so_texture = NULL;
	game->we_texture = NULL;
	game->ea_texture = NULL;
	game->floor_colours = NULL;
	game->ceiling_colours = NULL;
	game->true_game_map = NULL;
	game->no_texture_index = 0;
	game->so_texture_index = 0;
	game->we_texture_index = 0;
	game->ea_texture_index = 0;
	game->floor_colours_index = 0;
	game->ceiling_colours_index = 0;
	game->screen_h = 0;
	init_mouse(game);
	set_more_things(game);
}
