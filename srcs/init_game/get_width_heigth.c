/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width_heigth.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 15:10:07 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/07 14:39:55 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_width(t_game *game)
{
	long	max;
	long	temp;
	long	index;

	max = 0;
	index = 0;
	while (game->true_game_map[index] != NULL)
	{
		temp = 0;
		while (game->true_game_map[index][temp] != '\0'
			&& game->true_game_map[index][temp] != '\n')
		{
			if (temp > INT_MAX)
				return (-1);
			temp++;
		}
		if (temp > max)
			max = temp;
		index++;
	}
	return (max);
}

static int	get_heigth(t_game *game)
{
	long	index;

	index = 0;
	while (game->true_game_map[index] != NULL)
	{
		if (index > INT_MAX)
			return (-1);
		index++;
	}
	return (index);
}

int	get_width_heigth(t_game *game)
{
	game->width = get_width(game);
	if (game->width == -1)
		return (ft_putendl_fd_0("Error: invalid width", 2));
	game->width_map = game->width;
	game->width *= TILE_SIZE;
	game->heigth = get_heigth(game);
	if (game->heigth == -1)
		return (ft_putendl_fd_0("Error: invalid heigth", 2));
	game->heigth_map = game->heigth;
	game->heigth *= TILE_SIZE;
	if (!flood_fill(game))
		return (0);
	if (set_window(&game->mlx))
		return (0);
	mlx_get_screen_size(game->mlx.mlx_ptr, &game->screen_w, &game->screen_h);
	game->heigth = 1080;
	game->width = 1920;
	return (1);
}
