/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 09:11:23 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/17 11:13:12 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"


void check_exit(char **map, size_t py_c, size_t px_c, t_objects **status)
{
	if ( map[py_c][px_c] == 'E' && (*status)->collectible == 0)
		exit(0);
	if ((*status)->map[py_c][px_c] == 'E' && (*status)->collectible != 0)
		return;
}