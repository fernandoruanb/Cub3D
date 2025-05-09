/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_tex_colour.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 15:19:35 by jonas             #+#    #+#             */
/*   Updated: 2025/05/05 18:40:24 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_tex_x(t_dda *dda)
{
	int		tex_x;
	double	wall_x;

	if (dda->side == 0)
		wall_x = dda->py + dda->perpwalldist * dda->raydiry;
	else
		wall_x = dda->px + dda->perpwalldist * dda->raydirx;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * TILE_SIZE);
	if (tex_x < 0)
		tex_x = 0;
	if (tex_x >= TILE_SIZE)
		tex_x = TILE_SIZE - 1;
	if ((dda->side == 0 && dda->raydirx > 0)
		|| (dda->side == 1 && dda->raydiry < 0))
		tex_x = TILE_SIZE - tex_x - 1;
	return (tex_x);
}

static int	get_tex_y(t_dda *dda, int screen_h, int pitch, int y)
{
	int	temp;
	int	draw_start;

	draw_start = -dda->lineheight / 2 + screen_h / 2 + pitch;
	temp = ((y - draw_start) * TILE_SIZE) / dda->lineheight;
	if (temp < 0)
		temp = 0;
	if (temp >= TILE_SIZE)
		temp = TILE_SIZE - 1;
	return (temp);
}

static int	get_colour(t_tex *tex, int tex_x, int tex_y)
{
	return (*(int *)
		(tex->addr + tex_y * tex->linelen + tex_x * (tex->bpp / 8)));
}

static t_tex	*get_tex(t_game *game)
{
	if (game->dda.side == 0)
	{
		if (game->dda.raydirx < 0)
			return (&game->we);
		return (&game->ea);
	}
	if (game->dda.raydiry < 0)
		return (&game->no);
	return (&game->so);
}

int	get_tex_colour(t_game *game, int y)
{
	int		tex_x;
	int		tex_y;
	int		colour;
	t_tex	*tex;

	tex = get_tex(game);
	tex_x = get_tex_x(&game->dda);
	tex_y = get_tex_y(&game->dda, game->screen_h, game->pitch, y);
	colour = get_colour(tex, tex_x, tex_y);
	return (colour);
}
