/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_splits.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 15:02:04 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/01/26 10:41:30 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	clean(char *normal)
{
	if (normal)
		free(normal);
}

int	free_splits(char *normal, char **sp1, char **sp2, char **sp3)
{
	int	index;

	clean(normal);
	if (sp1)
	{
		index = 0;
		while (sp1[index])
			free(sp1[index++]);
		free(sp1);
	}
	if (sp2)
	{
		index = 0;
		while (sp2[index])
			free(sp2[index++]);
		free(sp2);
	}
	if (sp3)
	{
		index = 0;
		while (sp3[index])
			free(sp3[index++]);
		free(sp3);
	}
	return (1);
}
