/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:05:49 by jopereir          #+#    #+#             */
/*   Updated: 2025/04/21 13:07:08 by jopereir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	drawstr(char *str, int fd, int _return)
{
	if (!str)
		return (_return);
	while (*str)
		write(fd, str++, 1);
	return (_return);
}
