/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 03:41:20 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/14 00:27:44 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"
/* this function is used to create and return the matrix of the map*/
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
/*this function is used to get all the lines in the file*/
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
