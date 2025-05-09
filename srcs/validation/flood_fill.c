/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 19:50:38 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/07 19:16:03 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	free_map_copy(char **map, int flag)
{
	int	index;

	index = 0;
	while (map[index] != NULL)
	{
		free(map[index]);
		index++;
	}
	free(map);
	if (flag == 1)
		return (ft_putendl_fd_0("Error: Invalid map flood fill", 2));
	return (1);
}

static void	start_test_flood_fill(char **map, int x, int y, t_game *game)
{
	if (y < 0 || y >= game->heigth_map || x < 0 || x >= (int)ft_strlen(map[y]))
	{
		game->invalid_map = 1;
		return ;
	}
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	if (map[y][x] == ' ' || map[y][x] == '\t')
	{
		game->invalid_map = 1;
		return ;
	}
	map[y][x] = 'V';
	start_test_flood_fill(map, x + 1, y, game);
	start_test_flood_fill(map, x - 1, y, game);
	start_test_flood_fill(map, x, y + 1, game);
	start_test_flood_fill(map, x, y - 1, game);
}

static char	**emergency_free(char **map, int index)
{
	int	count;

	--index;
	count = 0;
	while (count < index)
	{
		free(map[count]);
		count++;
	}
	free(map);
	return (NULL);
}

static char	**get_map_copy(t_game *game)
{
	int		index;
	int		lines;
	char	**map;

	lines = get_all_lines(game);
	map = (char **)malloc((lines + 1) * sizeof(char *));
	if (!map)
		return (NULL);
	index = 0;
	while (game->true_game_map[index] != NULL)
	{
		map[index] = ft_strdup(game->true_game_map[index]);
		if (!map[index])
			return (emergency_free(map, index));
		index++;
	}
	map[index] = NULL;
	return (map);
}

int	flood_fill(t_game *game)
{
	char	**map_copy;
	int		i;
	int		c;

	map_copy = get_map_copy(game);
	if (!map_copy)
		return (0);
	i = 0;
	while (map_copy[i] != NULL)
	{
		c = 0;
		while (map_copy[i][c] != '\n' && map_copy[i][c] != '\0')
		{
			if (map_copy[i][c] == '0' || map_copy[i][c] == 'N'
				|| map_copy[i][c] == 'W' || map_copy[i][c] == 'S'
				|| map_copy[i][c] == 'E')
				start_test_flood_fill(map_copy, c, i, game);
			if (game->invalid_map == 1)
				return (free_map_copy(map_copy, 1));
			c++;
		}
		i++;
	}
	return (free_map_copy(map_copy, 0));
}
