/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fruan-ba <fruan-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 17:32:02 by fruan-ba          #+#    #+#             */
/*   Updated: 2025/04/22 11:17:55 by fruan-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*char	*epur_str(const char *str);

int	main(int argc, char **argv)
{
	char	*new_str;

	if (argc < 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	new_str = epur_str(argv[1]);
	ft_printf("%s", new_str);
	free(new_str);
	write(1, "\n", 1);
	return (0);
}*/

char	*epur_str(const char *str)
{
	int		index;
	int		count;
	char	*new_str;

	new_str = (char *)malloc(ft_strlen(str) + 1);
	if (!new_str)
		return (NULL);
	index = 0;
	count = 0;
	while (str[index] != '\0')
	{
		if (index == 0 && str[index] == ' ')
			index++;
		while (str[index] && str[index] == '\t')
			index++;
		if (str[index] == ' ' && (str[index + 1] != ' '
				&& str[index + 1] != '\t'))
			new_str[count++] = str[index];
		else if (str[index] != ' ')
			new_str[count++] = str[index];
		index++;
	}
	new_str[count] = '\0';
	return (new_str);
}
