/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/26 21:16:18 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/29 12:03:42 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_floor(t_game *game, int x)
{
	int	colour;
	int	y;

	colour = ft_atoi_base(game->rrggbb_floor + 2, 16);
	if (game->draw_3d_center_e > game->heigth)
		game->draw_3d_center_e = game->heigth;
	y = game->draw_3d_center_e;
	while (y < game->heigth)
	{
		mlx_pixel_put(game->mlx.mlx_ptr, game->mlx.win,
			x, y, colour);
		y++;
	}
}
