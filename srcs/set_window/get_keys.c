/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_keys.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 12:23:22 by jonas             #+#    #+#             */
/*   Updated: 2025/04/29 12:47:47 by jonas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_handle_key(int keycode, int set)
{
	static int	handle_key = 0;

	if (set)
		handle_key = keycode;
	return (handle_key);
}

t_keys	*get_keys(void)
{
	static t_keys	keys[5] = {
	{119, &move_w},
	{97, &move_a},
	{115, &move_s},
	{100, &move_d}};

	return (keys);
}
