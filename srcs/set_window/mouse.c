/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:42:49 by jonas             #+#    #+#             */
/*   Updated: 2025/05/07 22:57:44 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_struct(t_mouse *mouse, int x, int y)
{
	if (!mouse)
		return ;
	mouse->x = x;
	mouse->y = y;
}

static double	set_sensability(t_mouse *mouse, t_game *game)
{
	int	dir;

	dir = mouse->x - mouse->prev_x;
	if ((get_sign(dir) > 0 && mouse->prev_x > game->width / 2)
		|| (get_sign(dir) < 0 && mouse->prev_x < game->width / 2))
		mouse->prev_x = game->width / 2;
	else
		mouse->prev_x = mouse->x;
	if (abs(mouse->x - game->width / 2) > 2)
		mlx_mouse_move(game->mlx.mlx_ptr,
			game->mlx.win, game->width / 2, game->heigth / 2);
	return ((mouse->x - mouse->prev_x) * 0.001);
}

void	update_angle_mouse(t_game *game, t_mouse *mouse)
{
	game->angle += set_sensability(mouse, game);
	if (game->angle < 0)
		game->angle += 2 * M_PI;
	if (game->angle >= 2 * M_PI)
		game->angle -= 2 * M_PI;
	game->dir_x = cos(game->angle);
	game->dir_y = sin(game->angle);
	get_plane_x_y(game);
}

void	*get_target(t_mlx *mlx)
{
	int	h;
	int	w;

	return (mlx_xpm_file_to_image(mlx->mlx_ptr,
			"./images/MouseTarget3.xpm", &w, &h));
}

void	draw_mouse_target(t_mlx *mlx, t_mouse *mouse, int width, int height)
{
	if (!mouse->target)
		return ;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win,
		mouse->target, width / 2, height / 2);
}
