/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_security_on_map.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 16:11:20 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/03 18:58:16 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_security_on_map(t_game *game)
{
	int	index;

	index = 0;
	while (game->maps[index] != NULL)
	{
		if (ft_strncmp(game->maps[index], "NO", 2) == 0
			|| ft_strncmp(game->maps[index], "SO", 2) == 0
			|| ft_strncmp(game->maps[index], "WE", 2) == 0
			|| ft_strncmp(game->maps[index], "EA", 2) == 0
			|| ft_strncmp(game->maps[index], "\n", 1) == 0
			|| ft_strncmp(game->maps[index], "1", 1) == 0
			|| ft_strncmp(game->maps[index], "F", 1) == 0
			|| ft_strncmp(game->maps[index], "C", 1) == 0
			|| ft_strncmp(game->maps[index], " ", 1) == 0
			|| ft_strncmp(game->maps[index], "\t", 1) == 0)
			index++;
		else
			return (ft_putendl_fd_0("Error: Danger Zone", 2));
	}
	return (1);
}
