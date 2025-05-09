/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@42sp.org.br>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:36:33 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/01 12:26:24 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DDA_H
# define DDA_H

# include "cub3d.h"

void	init_camera_plane(t_game *game);
void	init_ray(t_game *game, int x);
void	init_dda_params(t_game *game, double px, double py);
void	dda_loop(t_game *game);
void	calculate_perp_dist_update_wall(t_game *game, double px, double py);
void	update_offset(t_game *game);

#endif /* DDA_H */
