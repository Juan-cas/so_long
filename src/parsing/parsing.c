/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 00:45:55 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/17 08:07:09 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

/*this function checks if the file is valid and it has the permisions
 * while returning the matrix created from the map file*/
char	**lets_parse_map(char **argv)
{
	int		fd;
	char	**map;

  if (ft_strlen(argv[1]) < 4)
    ft_error(4);
	if (ft_strlen(argv[1]) >= 4)
	{
		if (ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 4) != 0)
			ft_error(5);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	map = map_maker(fd);
	if (!map)
		return (NULL);
	return (map);
}

/*parses all the data toguether by calling each function*/
void	lets_parse_data(char **map, t_objects **status)
{
	map_check(map, status);
	if (!status)
		return ;
	flood_fill(map, status);
	final_check(map, status);
	free_coords(&(*status)->next);
}

/*a function that starts the parsing process and initiates
 * the structures*/
char	**init_parser(char **argv, t_objects **status)
{
	char	**map;

	map = NULL;
	init_status(status);
	map = lets_parse_map(argv);
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
