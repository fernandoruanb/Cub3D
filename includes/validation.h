/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jopereir <jopereir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 12:53:42 by jopereir          #+#    #+#             */
/*   Updated: 2025/04/22 12:28:38 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATION_H
# define VALIDATION_H

# include "cub3d.h"

int		check_cub(const char *filename);
int		free_game(t_game *game);
int		init_game(const char *filename, t_game *game);
char	**get_map(const char *filename);
int		free_game(t_game *game);
void	show_map(t_game *game);
void	init_all_things(t_game *game);
int		get_map_textures(t_game *game);
int		get_no_texture(t_game *game);
int		get_so_texture(t_game *game);
int		get_we_texture(t_game *game);
int		get_ea_texture(t_game *game);
int		get_floor_colours(t_game *game);
int		get_ceiling_colours(t_game *game);
int		get_true_map(t_game *game);
void	show_textures(t_game *game);
int		is_anything_null(t_game *game);
int		is_valid_map(t_game *game);
int		check_colours(t_game *game);
int		check_true_map(t_game *game);
int		check_is_valid_xpm(t_game *game);
int		check_elements(t_game *game);
int		check_entire_wall(t_game *game, int index);
int		check_first_last_wall(t_game *game, int index);
size_t	get_all_lines(t_game *game);
int		check_invalid_access(t_game *game);
int		flood_fill(t_game *game);
int		check_security_on_map(t_game *game);
int		check_is_anything_equal(t_game *game);
int		check_repeat_textures(t_game *game);
int		check_split_length(char **split);
void	remove_spaces_and_tabs(char ***str);

#endif
