/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 03:41:20 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/12 03:16:33 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

static char	**map_matrix(char **str)
{
	char	**map;

	map = ft_split(*str, '\n');
	if (!map)
	{
		matrix_clear(map);
	}
	free(*str);
	return (map);
}

char	**map_maker(int fd)
{
	char	*str;
	char	*temp;

	str = NULL;
	while (1)
	{
		temp = get_next_line(fd);
		if (temp == NULL)
			break ;
		str = append(str, temp);
		if (!str)
			ft_error(2);
	}
	return (map_matrix(&str));
}
