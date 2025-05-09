/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_is_anything_equal.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 17:17:08 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/22 12:56:32 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	emperor_decision(char **checker)
{
	int	index;
	int	count;

	index = 0;
	while (checker[index] != NULL)
	{
		count = index + 1;
		while (checker[count] != NULL)
		{
			if (ft_strcmp(checker[index], checker[count]) == 0)
				return (1);
			count++;
		}
		index++;
	}
	return (0);
}

int	check_is_anything_equal(t_game *game)
{
	char	*checker[5];

	checker[0] = game->no_texture;
	checker[1] = game->so_texture;
	checker[2] = game->we_texture;
	checker[3] = game->ea_texture;
	checker[4] = NULL;
	if (emperor_decision(checker))
		return (ft_putendl_fd_0("Error: Duplicate files found", 2));
	return (1);
}
