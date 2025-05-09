/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 15:46:00 by jonas             #+#    #+#             */
/*   Updated: 2025/05/07 23:05:20 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fps_control(t_game *game)
{
	static int	frame_skip = 0;

	if (frame_skip++ < 5)
		return ;
	frame_skip = 0;
	render_the_3d(game);
}
