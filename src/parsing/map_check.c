/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 00:38:19 by juan-cas          #+#    #+#             */
/*   Updated: 2024/11/24 00:04:27 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

/**
 * @brief checks the map
 * this function ensures there are at least 1 player, 1 exit, 1 collectible
 *  in the map
 *  @param status the structure containing all the data from the map.
 */
static void	objects_check(t_objects *status)
{
	if (status->player != 1)
		ft_error(3);
	if (status->exit != 1)
		ft_error(3);
	if (status->collectible == 0)
		ft_error(3);
}

/*funtion to check if the map only contains valid characters*/
/**
 * @brief checks if the map contains only valid characters
 * @param status the structure that contains all the data.
 */
static void	is_map_valid(char *map, t_objects *status)
{
	size_t	j;

	j = 0;
	while (map[j])
	{
		if (j == 0 && !is1(map[j]))
			ft_error(3);
		if (j == ft_strlen(map) - 1 && !is1(map[j]))
			ft_error(3);
		else if (!is1(map[j]) && !is0(map[j]) && !isc(map[j], status)
			&& !ise(map[j], status) && !isp(map[j], status))
			ft_error(3);
		j++;
	}
}

/**
 * @brief parses the map and the structure containing the map.
 * @param status structure containing the map data.
 * @param map the matrix containing the map.
 */
static void	parsing(char **map, t_objects *status)
{
	size_t	i;

	i = -1;
	while (map[++i])
	{
		if (ft_strlen(map[i]) != status->map_length)
			ft_error(3);
		else if ((i == 0 || i == status->map_lines) && !line1(map[i]))
			ft_error(3);
		else
			is_map_valid(map[i], status);
	}
	objects_check(status);
}

/**
 * @brief checks how many lines the matrix has.
 * @param map the map matrix.
 */
static size_t	how_many_lines(char **map)
{
	size_t	lines;

	lines = -1;
	while (map[++lines])
		;
	return (lines);
}

/**
 * @brief parses the entire map
 * This function checks the entire map, and that the data we will handle
 * passes all of our checks, before proceeding.
 * @param status structure containing our map data.
 * @param map our map matrix.
 */
void	map_check(char **map, t_objects **status)
{
	(*status)->map_lines = how_many_lines(map);
	(*status)->map_length = ft_strlen(map[0]);
	parsing(map, (*status));
	if ((*status)->map_length > 80)
	{
		ft_putstr_fd("map length is above what can be rendered", 2);
		exit(1);
	}
	if ((*status)->map_lines > 41)
	{
		ft_putstr_fd("map height is above what can be rendered", 2);
		exit(1);
	}
}
