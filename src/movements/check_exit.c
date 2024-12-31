/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:11:23 by juan-cas          #+#    #+#             */
/*   Updated: 2024/11/21 00:39:11 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

/**
 * @brief checks if the spot is the exit -> E
 * Checks if all collectibles have been collected in order to allow the
 * player to exit the game.
 * @param map map matrix
 * @param status structure containing all the information for the game to
 * function.
 * @param px_c x coordinates of the player.
 * @param py_c y coordinates of the player.
 */
void	check_exit(char **map, size_t py_c, size_t px_c, t_objects **status)
{
	if (map[py_c][px_c] == 'E' && (*status)->collectible == 0)
	{
		step_printer((*status)->steps);
		exit(0);
	}
	if ((*status)->map[py_c][px_c] == 'E' && (*status)->collectible != 0)
		return ;
}
