/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pipes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 15:31:44 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/25 15:55:17 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	create_pipes(int argc, int pipefds[][2])
{
	int	index;

	index = 0;
	while (index < argc - 1)
	{
		if (pipe(pipefds[index]) == -1)
		{
			while (index > 0)
			{
				index--;
				close_descriptors(pipefds[index], NULL);
			}
			return (ft_putendl_fd_0("Error creating pipe.", 2));
		}
		index++;
	}
	return (1);
}
