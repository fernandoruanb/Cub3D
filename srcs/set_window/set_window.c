/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_window.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:02:35 by jopereir          #+#    #+#             */
/*   Updated: 2025/05/07 23:13:55 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	set_window(t_mlx *mlx)
{
	int	win_w;
	int	win_h;

	if (!mlx)
		return (1);
	win_w = 1920;
	win_h = 1080;
	mlx->win = mlx_new_window(mlx->mlx_ptr, win_w, win_h, "cub3d");
	if (!mlx->win)
		return (drawstr("Error: Couldn't open the window\n", 2, 1));
	return (0);
}
