/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 22:45:10 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/04 11:24:23 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_length(char *high, char *little, size_t length)
{
	size_t	index;
	size_t	little_len;

	little_len = ft_strlen(little);
	if (little_len > length)
		return (0);
	index = length - little_len;
	while (index > 0 && (high[index - 1] == ' '
			|| high[index - 1] == '\t'))
		--index;
	return (index == 0);
}

int	find_texture(char *high, char *little, int i)
{
	size_t		index;
	size_t		length;
	char		*find;

	if (!high || !little)
		return (0);
	index = 0;
	length = ft_strlen(high);
	while (high[index] != '\n' && high[index] != '\0')
	{
		find = ft_strnstr(high, little, ft_strlen(high));
		if (find != NULL)
		{
			if (ft_strncmp(find, little, i) == 0)
			{
				if (!check_length(high, find, length))
					return (0);
				return (1);
			}
		}
		index++;
	}
	return (0);
}
