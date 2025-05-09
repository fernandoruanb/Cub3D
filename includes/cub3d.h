/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:31:34 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/09 12:19:27 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "structs.h"
# include "validation.h"
# include "window.h"
# include "ray_cast.h"
# include "dda.h"
# include "mouse.h"

# define COLOUR_FLOOR 0xff0000
# define COLOUR_WALL 0xFFD700
# define COLOUR_PLAYER 0x0000ff
# define COLOUR_DEFAULT 0x228Bff
# define COLOUR_RADIUS 0x0000ff
# define MINIMAP_SCALE 0.5
# define MOVE_SPEED 10
# define ROTATION_SPEED 0.1
# define VISUAL_CAMP 0.8
# define PITCH_STEP 20

int		destroy(t_game *game);
int		get_width_heigth(t_game *game);
t_game	*get_t_game(void);
void	draw_radius(t_game *game);
void	update_angle_dir_x_y(t_game *game, int keycode);
void	get_distance(t_game *game, int flag);
int		check_and_set_images(t_game *game);
void	init_all_3d(t_game *game);
void	render_the_3d(t_game *game);
void	draw_floor(t_game *game, int x);
void	draw_ceiling(t_game *game, int x);
int		can_move(t_game *game, double next_x, double next_y);
void	move_a(t_game *game);
void	move_w(t_game *game);
void	move_s(t_game *game);
void	move_d(t_game *game);
void	get_plane_x_y(t_game *game);
int		find_texture(char *high, char *little, int i);
void	update_angle_mouse(t_game *game, t_mouse *mouse);
void	fps_control(t_game *game);
int		find_another(char **map, int index, char *target);

#endif /* CUB3D_H */
