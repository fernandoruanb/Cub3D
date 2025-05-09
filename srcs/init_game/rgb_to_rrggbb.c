/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_rrggbb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 16:58:45 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/23 09:00:18 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	calculate_hex_length(unsigned int number);

static char	*int_to_hex(unsigned int target, char specifier)
{
	char			*hex_digits;
	unsigned int	length;
	unsigned int	number;
	char			*buffer;

	if (specifier == 'x')
		hex_digits = "0123456789abcdef";
	else
		hex_digits = "0123456789ABCDEF";
	number = target;
	length = calculate_hex_length(number);
	buffer = (char *)malloc(length + 1);
	if (!buffer)
		return (NULL);
	buffer[length] = '\0';
	while (length--)
	{
		buffer[length] = hex_digits[number % 16];
		number /= 16;
	}
	return (buffer);
}

static int	calculate_hex_length(unsigned int number)
{
	unsigned int	length;

	length = 0;
	if (number == 0)
		length = 1;
	while (number)
	{
		number /= 16;
		length++;
	}
	if (length < 2)
		length = 2;
	return (length);
}

static char	*get_rrggbb(char **target)
{
	char	*new;
	char	*new2;
	char	*new3;
	char	*temp;

	new = int_to_hex(ft_atoi(target[0]), 'x');
	new2 = int_to_hex(ft_atoi(target[1]), 'x');
	new3 = int_to_hex(ft_atoi(target[2]), 'x');
	temp = ft_strjoin(new, new2);
	free(new);
	new = ft_strjoin(temp, new3);
	free(temp);
	free(new2);
	free(new3);
	temp = ft_strjoin("0x", new);
	free(new);
	new = temp;
	return (new);
}

int	rgb_to_rrggbb(t_game *game)
{
	char	**target;

	target = ft_split(game->floor_colours, ',');
	if (!target)
		return (0);
	game->rrggbb_floor = get_rrggbb(target);
	free_splits(NULL, target, NULL, NULL);
	if (!game->rrggbb_floor)
		return (0);
	target = ft_split(game->ceiling_colours, ',');
	if (!target)
		return (0);
	game->rrggbb_ceiling = get_rrggbb(target);
	free_splits(NULL, target, NULL, NULL);
	if (!game->rrggbb_ceiling)
		return (0);
	return (1);
}
