/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_another.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 21:25:29 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/09 12:21:44 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	find_another(char **map, int index, char *target)
{
	char	*find;
	int		length;

	find = NULL;
	++index;
	while (map[index] != NULL)
	{
		length = (int)ft_strlen(map[index]);
		find = ft_strnstr(map[index], target, length);
		if (find != NULL)
			return (ft_putendl_fd_1("Error: Duplicate texture", 2));
		index++;
	}
	return (0);
}
