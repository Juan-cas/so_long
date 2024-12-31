/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_maker.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 03:41:20 by juan-cas          #+#    #+#             */
/*   Updated: 2024/11/21 00:23:31 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

/**
 * @brief returns the map turned int a matrix **
 * @param str the whole string obtained from the file.
 */
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
/**
 * @brief this function returns the map already turned into a
 * matrix **
 * @param receives the fd that will be used in order to open
 * the file containing the map.
 */
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
	close(fd);
	return (map_matrix(&str));
}
