/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_all_pipes_also_fd.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 20:28:25 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/25 20:28:47 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	clean_all_pipes_also_fd(int argc, int pipefds[][2], int fd)
{
	int	index;

	index = 0;
	while (index < argc - 1)
	{
		close_descriptors(pipefds[index], NULL);
		index++;
	}
	if (fd > 2)
		close(fd);
	return (1);
}
