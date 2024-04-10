/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_populator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 06:12:16 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/08 21:24:13 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void sort_populate(char c, int width, int height, t_data **data)
{
	if (c == '0')
		mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,(*data)->textures[0], width, height);
	if (c == 'P')
		mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr, (*data)->textures[1], width, height);
	if (c == 'C')
		mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,(*data)->textures[2], width, height);
	if (c == '1')
		mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,(*data)->textures[3], width, height);
	if (c == 'E')
		mlx_put_image_to_window((*data)->mlx_ptr, (*data)->win_ptr,(*data)->textures[4], width, height);
}

void populate_window(char **map, t_data **data)
{
	int	i;
	int	j;
	int width;
	int height;

	i = -1;
	height = 0;
	while (map[++i])
	{
		j = -1;
		width = 0;
		while(map[i][++j])
		{
			sort_populate(map[i][j], width, height, data);
			width += 32;
		}
		height += 32;
	}
}
