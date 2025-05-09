/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_all_pipes.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 17:05:12 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/25 17:29:04 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	clean_all_pipes(int argc, int pipefds[][2])
{
	int	index;

	index = 0;
	while (index < argc - 1)
	{
		close_descriptors(pipefds[index], NULL);
		index++;
	}
}
