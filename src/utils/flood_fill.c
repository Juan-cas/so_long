/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 03:15:46 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/14 00:04:38 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

/*a basic floodfill algorithm that paints the whole map from the player
 * starting position until it has gone through all the squares he can
 * posibly enter to*/

static void	crawler(char **map, size_t y, size_t x, t_objects **status)
{
	if (y >= (*status)->map_lines || x >= (*status)->map_length)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'E')
		return ;
	if (map[y][x] == 'P' && (*status)->init_pos_flood == 1)
		return ;
	if ((*status)->init_pos_flood == 0)
		(*status)->init_pos_flood = 1;
	if (map[y][x] == 'C')
	{
		collx_y(y, x, status);
		(*status)->col_check++;
		map[y][x] = 'P';
	}
	else
		map[y][x] = 'P';
	crawler(map, y + 1, x, status);
	crawler(map, y - 1, x, status);
	crawler(map, y, x + 1, status);
	crawler(map, y, x - 1, status);
}

/* verifier:
 * a funtion that gets the coordinates of all the collectibles
 * then executes the floodfill and checks the number of collectibles*/

void	flood_fill(char **map, t_objects **status)
{
	find_coords_p(map, status);
	crawler(map, (*status)->py_coord, (*status)->px_coord, status);
	if ((*status)->col_check != (*status)->collectible)
	{
		perror("Invalid map");
		exit(1);
	}
}
