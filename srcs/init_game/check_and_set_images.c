/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_set_images.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 17:54:50 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/07 15:00:54 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	get_all_images_addr(t_game *game)
{
	game->no.addr = mlx_get_data_addr(game->no_img, &game->no.bpp,
			&game->no.linelen, &game->no.endian);
	if (!game->no.addr)
		return (0);
	game->so.addr = mlx_get_data_addr(game->so_img, &game->so.bpp,
			&game->so.linelen, &game->so.endian);
	if (!game->so.addr)
		return (0);
	game->we.addr = mlx_get_data_addr(game->we_img, &game->we.bpp,
			&game->we.linelen, &game->we.endian);
	if (!game->we.addr)
		return (0);
	game->ea.addr = mlx_get_data_addr(game->ea_img, &game->ea.bpp,
			&game->ea.linelen, &game->ea.endian);
	if (!game->ea.addr)
		return (0);
	return (1);
}

int	check_and_set_images(t_game *game)
{
	int	width;
	int	heigth;

	game->no_img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->no_texture, &width, &heigth);
	if (!game->no_img || width != TILE_SIZE || heigth != TILE_SIZE)
		return (0);
	game->so_img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->so_texture, &width, &heigth);
	if (!game->so_img || width != TILE_SIZE || heigth != TILE_SIZE)
		return (0);
	game->we_img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->we_texture, &width, &heigth);
	if (!game->we_img || width != TILE_SIZE || heigth != TILE_SIZE)
		return (0);
	game->ea_img = mlx_xpm_file_to_image(game->mlx.mlx_ptr,
			game->ea_texture, &width, &heigth);
	if (!game->ea_img || width != TILE_SIZE || heigth != TILE_SIZE)
		return (0);
	game->mouse.target = get_target(&game->mlx);
	if (!get_all_images_addr(game))
		return (0);
	return (1);
}
