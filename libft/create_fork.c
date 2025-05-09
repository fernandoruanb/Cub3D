/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_fork.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 16:40:33 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/25 16:41:10 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	create_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (ft_putendl_fd_0("Error creating forks.", 2));
	return (pid);
}
