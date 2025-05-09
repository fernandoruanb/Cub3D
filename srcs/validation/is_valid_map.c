/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 15:53:26 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/03 21:57:43 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_textures(t_game *game)
{
	if (is_anything_null(game))
		return (ft_putendl_fd_0("Error: anything null found!", 2));
	if (!check_colours(game))
		return (0);
	if (!check_is_valid_xpm(game))
		return (0);
	return (1);
}

int	is_valid_map(t_game *game)
{
	if (!check_textures(game))
		return (0);
	if (!check_true_map(game))
		return (0);
	if (!check_elements(game))
		return (0);
	if (!check_is_anything_equal(game))
		return (0);
	return (1);
}
