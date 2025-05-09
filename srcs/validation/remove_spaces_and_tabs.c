/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_spaces_and_tabs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonas <jonas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:35:43 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/22 12:46:14 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static int	is_only_spaces(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
	{
		if (str[index] != ' ' && str[index] != '\t'
			&& str[index] != '\n')
			return (0);
		index++;
	}
	return (1);
}

static char	*do_magic(char *str, int *flag)
{
	char	*new_str;
	size_t	length;
	int		index;
	int		count;

	length = ft_strlen(str);
	if (is_only_spaces(str))
	{
		*flag = 0;
		return (NULL);
	}
	new_str = (char *)malloc(length + 1);
	if (!new_str)
		return (NULL);
	index = 0;
	count = 0;
	while (str[index] != '\0')
	{
		if (str[index] != ' ' && str[index] != '\t'
			&& str[index] != '\n')
			new_str[count++] = str[index];
		index++;
	}
	new_str[count] = '\0';
	return (new_str);
}

void	remove_spaces_and_tabs(char ***split)
{
	int		index;
	int		length;
	char	*new_str;
	int		flag;

	length = 0;
	while ((*split)[length] != NULL)
		length++;
	if (length < 2)
		return ;
	index = 0;
	while ((*split)[index] != NULL)
	{
		flag = 1;
		new_str = do_magic((*split)[index], &flag);
		if (!new_str && flag != 0)
			return ;
		free((*split)[index]);
		(*split)[index] = new_str;
		index++;
	}
}
