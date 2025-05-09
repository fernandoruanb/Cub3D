/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 18:29:29 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/05/07 23:09:43 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	check_can_open_read_file(char *filename)
{
	int		fd;
	char	buffer[100];
	ssize_t	bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (ft_putendl_fd_0("Error: unable to open file", 2));
	bytes_read = read(fd, buffer, sizeof(bytes_read));
	if (bytes_read == -1 || bytes_read == 0)
		return (ft_putendl_fd_0("Error: unable to read the file", 2));
	close(fd);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc < 2)
		return (ft_putendl_fd_1("How to use: ./cub3d <map.cub>", 2));
	if (!check_can_open_read_file(argv[1]))
		return (1);
	if (!check_cub(argv[1]))
		return (1);
	game = get_t_game();
	if (!init_game(argv[1], game))
		destroy(game);
	mlx_mouse_hide(game->mlx.mlx_ptr, game->mlx.win);
	run_window(game);
	return (destroy(game));
}
