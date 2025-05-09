/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 13:01:59 by jopereir          #+#    #+#             */
/*   Updated: 2025/05/07 23:14:03 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WINDOW_H
# define WINDOW_H

# include "cub3d.h"

int		drawstr(char *str, int fd, int _return);
int		set_window(t_mlx *mlx);
void	run_window(t_game *game);
int		get_handle_key(int keycode, int set);
t_keys	*get_keys(void);

#endif
