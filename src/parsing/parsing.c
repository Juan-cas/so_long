/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 00:45:55 by juan-cas          #+#    #+#             */
/*   Updated: 2024/11/21 00:20:03 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

/**
 *  @brief this function checks the map
 *  It checks that the filename being passed to it as an argument
 *  is valid and contains a proper map
 *  @param argv filename (ej map.ber)
 *  @param fd the int that will store the fd
 */
char	**lets_parse_map(char **argv, int fd)
{
	char	**map;
	int		i;
	char	*tmp;

	i = 0;
	if (ft_strlen(argv[1]) < 4)
		ft_error(4);
	if (ft_strlen(argv[1]) >= 4)
	{
		if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 4) != 0)
			ft_error(5);
		tmp = ft_strrchr(argv[1], '.');
		while (tmp[i] != '\0')
			i++;
		if (i > 4)
			ft_error(5);
	}
	map = map_maker(fd);
	if (!map)
	{
		ft_error(7);
		exit (1);
	}
	return (map);
}

/**
 * @brief parses the data to ensure our structure
 * has all data it needs saved correctly.
 * @param status the structure where we save all
 * the parsed data.
 * @param map the map that will be parsed.
 */
void	lets_parse_data(char **map, t_objects **status)
{
	map_check(map, status);
	if (!status)
		exit (1);
	flood_fill(map, status);
	final_check(map, status);
	free_coords(&(*status)->next);
}

/**
 * @brief this function parses the map.
 * @param argv raw parameters from stdin.
 * @param status the stucture that saves all the parsed data.
 * @param fd the file descriptor with the file opened
 * that will be parsed.
 */
char	**init_parser(char **argv, t_objects **status, int fd)
{
	char	**map;

	map = NULL;
	init_status(status);
	map = lets_parse_map(argv, fd);
	if (!map)
	{
		free(status);
		exit(1);
	}
	lets_parse_data(map, status);
	if (!status)
	{
		matrix_clear(map);
		free(status);
		exit(1);
	}
	return (map);
}
