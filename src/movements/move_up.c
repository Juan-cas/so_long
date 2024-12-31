/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_up.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:27:12 by juan-cas          #+#    #+#             */
/*   Updated: 2024/07/14 17:31:44 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

static void	up(char **map, size_t py_c, size_t px_c, t_objects **status)
{
	if (map[py_c - 1][px_c] == 'C')
	{
		map[py_c - 1][px_c] = 'P';
		map[py_c][px_c] = '0';
		(*status)->py_coord -= 1;
		(*status)->collectible--;
	}
	else if (map[py_c - 1][px_c] == '0')
	{
		map[py_c - 1][px_c] = 'P';
		map[py_c][px_c] = '0';
		(*status)->py_coord -= 1;
	}
	else
		check_exit(map, py_c - 1, px_c, status);
	if (map[py_c - 1][px_c] != 'E')
	{
		step_printer((*status)->steps);
		(*status)->steps++;
	}
	populate_window(status);
}

/**
 * @brief moves the character north if possible
 * This function rewrites both the next letter north and the previous
 * letter where the character was, allowing the map to display the player
 * in a new place.
 * @param status structure containing the data of the map.
 */
void	move_north(t_objects **status)
{
	size_t	py_c;
	size_t	px_c;

	py_c = (*status)->py_coord;
	px_c = (*status)->px_coord;
	if ((*status)->map[(*status)->py_coord - 1][(*status)->px_coord] != '1')
	{
		up((*status)->map, py_c, px_c, status);
	}
}
