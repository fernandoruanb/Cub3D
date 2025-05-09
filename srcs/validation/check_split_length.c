/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_split_length.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 19:01:43 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/22 12:57:47 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_split_length(char **split)
{
	int	index;

	index = 0;
	while (split[index] != NULL)
		index++;
	if (index != 2)
		return (ft_putendl_fd_0("Error: Invalid texture length", 2));
	return (1);
}
