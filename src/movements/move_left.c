/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_left.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:05:33 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/17 12:44:48 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

static void left(char **map, size_t py_c, size_t px_c, t_objects **status)
{
	if (map[py_c][px_c - 1] == 'C')
	{
		map[py_c][px_c - 1] = 'P';
		map[py_c][px_c] = '0';
		(*status)->px_coord -= 1;
		(*status)->collectible--;
	}
	else if (map[py_c][px_c - 1] == '0')
	{
		map[py_c][px_c - 1] = 'P';
		map[py_c][px_c] = '0';
		(*status)->px_coord -= 1;
	}
	else
		check_exit(map, py_c, px_c - 1, status);

	populate_window(status);
}

void	move_left(t_objects **status)
{
	size_t py_c;
	size_t px_c;

	py_c = (*status)->py_coord;
	px_c = (*status)->px_coord;
	if ((*status)->map[(*status)->py_coord ][(*status)->px_coord - 1] != '1')
	{
		left((*status)->map, py_c, px_c, status);
	}
}