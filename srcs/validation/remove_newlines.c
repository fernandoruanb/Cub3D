/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_newlines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/25 19:22:26 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/25 19:55:27 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	remove_newlines(t_game *game)
{
	game->no = ft_strdup(game->no_texture - 1);
	game->so = ft_strdup(game->so_texture - 1);
	game->we = ft_strdup(game->we_texture - 1);
	game->ea = ft_strdup(game->ea_texture - 1);
	return (ultimate_case(game));
}
