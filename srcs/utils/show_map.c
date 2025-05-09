/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 22:44:57 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/19 14:33:13 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	show_map(t_game *game)
{
	int	index;

	if (!game)
		return ;
	if (game->maps)
	{
		index = 0;
		while (game->maps[index] != NULL)
		{
			if (game->maps[index + 1] == NULL)
				ft_printf("%s\n", game->maps[index]);
			else
				ft_printf("%s", game->maps[index]);
			index++;
		}
	}
}
