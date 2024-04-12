/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_coords.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:52:14 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/12 03:15:18 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

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
