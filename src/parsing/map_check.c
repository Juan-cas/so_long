/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 00:38:19 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/07 20:42:29 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../solong.h"

static void objects_check(t_objects *status)
{
	if (status->player != 1)
		ft_error(3);
	if (status->exit != 1)
		ft_error(3);
	if (status->collectible == 0)
		ft_error(3);
}

static void is_map_valid(char *map, t_objects *status)
{
	size_t j;

	j = 0;
	while(map[j])
	{
		if (j == 0 && !is1(map[j]))
			ft_error(3);
		if (j == ft_strlen(map) - 1 && !is1(map[j]))
			ft_error(3);
		else if (!is1(map[j]) && !is0(map[j]) && !isc(map[j], status) \
			&& !ise(map[j], status) && !isp(map[j], status))
			ft_error(3);
		j++;
 	}
}

static void parsing(char **map, t_objects *status)
{
	size_t i;

	i = -1;
	while (map[++i])
	{
		if (ft_strlen(map[i]) != status->map_length)
			ft_error(3);
		else if ((i == 0 || i == status->map_lines) && !line1(map[i++]))
			ft_error(3);
		else
			is_map_valid(map[i], status);
	}
	objects_check(status);
}

static size_t how_many_lines(char **map)
{
	size_t	lines;

	lines = -1;
	while(map[++lines]);
	return (lines);
}

void map_check(char **map, t_objects **status)
{
	(*status)->map_lines = how_many_lines(map);
	(*status)->map_length = ft_strlen(map[0]);
	parsing(map, (*status));
	if ((*status)->map_length > 60)
	{
		ft_putstr_fd("map length is above what can be rendered", 2);
		matrix_clear(map);
		free(status);
		exit(1);
	}
	if ((*status)->map_lines > 30)
	{
		ft_putstr_fd("map height is above what can be rendered", 2);
		matrix_clear(map);
		free(status);
		exit(1);
	}
}