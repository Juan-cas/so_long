/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 14:28:31 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/08 06:06:11 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../solong.h"

void init_status(t_objects **status)
{
	(*status)->player = 0;
	(*status)->collectible = 0;
	(*status)->exit = 0;
	(*status)->map_length = 0;
	(*status)->map_lines = 0;
	(*status)->py_coord = 0;
	(*status)->px_coord = 0;
	(*status)->col_x = 0;
	(*status)->col_y = 0;
	(*status)->col_check = 0;
	(*status)->init_pos_flood = 0;
	(*status)->ey_coord = 0;
	(*status)->ex_coord = 0;
}

void assign_textures(t_objects **status, int j)
{
	int width;
	int height;

	if (j == 0)
		(*status)->textures[0] = mlx_xpm_file_to_image((*status)->mlx_ptr, floor_sprite, &width, &height);
	if (j == 1)
		(*status)->textures[1] = mlx_xpm_file_to_image((*status)->mlx_ptr, player_sprite, &width, &height);
	if (j == 2)
		(*status)->textures[2] = mlx_xpm_file_to_image((*status)->mlx_ptr, potion_sprite, &width, &height);
	if (j == 3)
		(*status)->textures[3] = mlx_xpm_file_to_image((*status)->mlx_ptr, wall_sprite, &width, &height);
	if (j == 4)
		(*status)->textures[4] = mlx_xpm_file_to_image((*status)->mlx_ptr, exit_door_sprite, &width, &height);
	if (!(*status)->textures[j])
		exit(1);
}

void textures_init(t_objects **status, char **map_board)
{
	int j;
	j =	0;
	while (j < 5)
		assign_textures(status, j++);
  
	(*status)->winysize = (*status)->map_lines * 32;
	(*status)->winxsize = (*status)->map_length * 32;
  (*status)->map = map_board;
}
