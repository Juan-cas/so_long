/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   north_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 08:27:12 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/17 08:29:04 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

static void	lets_move_nort(t_objects **status, size_t flag)
{
	if ((*status)->map[(*status)->py_coord - 1][(*status)->px_coord] == 'C')
	{
		(*status)->map[(*status)->py_coord - 1][(*status)->px_coord] = 'P';
		(*status)->map[(*status)->py_coord][(*status)->px_coord] = '0';
		(*status)->py_coord -= 1;
		put_floor(status, (*status)->px_coord * 32, (*status)->py_coord * 32);
		(*status)->collectible--;
	}
	else if ((*status)->map[(*status)->py_coord - 1]
              [(*status)->px_coord] == '0')
	{
		(*status)->map[(*status)->py_coord - 1][(*status)->px_coord] = 'P';
		(*status)->map[(*status)->py_coord][(*status)->px_coord] = '0';
		(*status)->py_coord -= 1;
	}
	else if ((*status)->map[(*status)->py_coord - 1][(*status)->px_coord] == 'E'
		&& (*status)->collectible == flag)
		exit(0);
	else if ((*status)->map[(*status)->py_coord - 1][(*status)->px_coord] == 'E'
		&& (*status)->collectible != flag)
		return ;
	populate_window(status);
}

void	move_north(t_objects **status, size_t flag)
{
	if ((*status)->map[(*status)->py_coord - 1][(*status)->px_coord] != '1')
	{
		lets_move_nort(status, flag);
	}
}
