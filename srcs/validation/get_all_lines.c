/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_all_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 16:59:13 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/20 17:47:07 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

size_t	get_all_lines(t_game *game)
{
	size_t	lines;

	lines = 0;
	while (game->true_game_map[lines] != NULL)
		lines++;
	return (lines);
}
