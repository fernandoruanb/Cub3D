/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_colours.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 16:34:13 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/04 11:41:34 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_is_only_numbers(char **colours)
{
	int	index;
	int	count;

	index = 0;
	while (colours[index] != NULL)
	{
		count = 0;
		if (count == 0)
		{
			if (colours[index][count] == '-')
				count++;
		}
		while (colours[index][count] != '\n'
			&& colours[index][count] != '\0')
		{
			if (!ft_isdigit(colours[index][count]))
				return (ft_putendl_fd_0("Error: Crazy RGB", 2));
			count++;
		}
		index++;
	}
	return (1);
}

static int	check_rgb(char **colours)
{
	int	n1;
	int	n2;
	int	n3;

	if (!check_is_only_numbers(colours))
		return (0);
	n1 = ft_atoi(colours[0]);
	n2 = ft_atoi(colours[1]);
	n3 = ft_atoi(colours[2]);
	if (n1 < 0 || n1 > 255 || n2 < 0 || n2 > 255 || n3 < 0 || n3 > 255)
		return (ft_putendl_fd_0("Error: invalid RGB range", 2));
	return (1);
}

static int	check_length_colours(char **colours)
{
	int	length;

	length = 0;
	while (colours[length] != NULL)
		length++;
	if (length != 3)
		return (ft_putendl_fd_0("Error: invalid length RGB", 2));
	return (1);
}

static int	check_all(char **colours)
{
	if (!check_length_colours(colours))
	{
		free_splits(NULL, colours, NULL, NULL);
		return (0);
	}
	if (!check_rgb(colours))
	{
		free_splits(NULL, colours, NULL, NULL);
		return (0);
	}
	free_splits(NULL, colours, NULL, NULL);
	return (1);
}

int	check_colours(t_game *game)
{
	char	**colours;

	colours = ft_split(game->floor_colours, ',');
	if (!colours)
		return (0);
	if (!check_all(colours))
		return (0);
	colours = ft_split(game->ceiling_colours, ',');
	if (!colours)
		return (0);
	if (!check_all(colours))
		return (0);
	return (1);
}
