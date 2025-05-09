/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:44:27 by jonas             #+#    #+#             */
/*   Updated: 2025/05/07 15:13:19 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_H
# define MOUSE_H

# include "cub3d.h"

void	fill_struct(t_mouse *mouse, int x, int y);
void	update_angle_mouse(t_game *game, t_mouse *mouse);
void	draw_mouse_target(t_mlx *mlx, t_mouse *mouse, int width, int height);
void	*get_target(t_mlx *mlx);
int		get_sign(int n);

#endif
