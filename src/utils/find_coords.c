/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_coords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:52:14 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/14 00:06:49 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

/* finds and saves the coordinates of the exit*/
void	find_coords_e(char **map, t_objects **status)
{
	while (map[(*status)->ey_coord])
	{
		(*status)->ex_coord = 0;
		while (map[(*status)->ey_coord][(*status)->ex_coord])
		{
			if (map[(*status)->ey_coord][(*status)->ex_coord] == 'E')
				return ;
			(*status)->ex_coord++;
		}
		(*status)->ey_coord++;
	}
}
/*finds and saves the coordinates of the player*/
void	find_coords_p(char **map, t_objects **status)
{
	while (map[(*status)->py_coord])
	{
		(*status)->px_coord = 0;
		while (map[(*status)->py_coord][(*status)->px_coord])
		{
			if (map[(*status)->py_coord][(*status)->px_coord] == 'P')
				return ;
			(*status)->px_coord++;
		}
		(*status)->py_coord++;
	}
}
