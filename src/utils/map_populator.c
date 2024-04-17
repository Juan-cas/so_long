/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_populator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 06:12:16 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/17 12:23:19 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

/* sorter AND populate
 * this function receives c and compares it againts the sprite that will be
 * printed, aside from width & height to locate where the image will be
 * printed in the window*/
static void	sort_populate(char c, int width, int height, t_objects **status)
{
	if (c == '0')
		mlx_put_image_to_window((*status)->mlx_ptr, (*status)->win_ptr,
			(*status)->textures[0], width, height);
	if (c == 'P')
	{
		put_floor(status, width, height);
		mlx_put_image_to_window((*status)->mlx_ptr, (*status)->win_ptr,
			(*status)->textures[1], width, height);
	}
	if (c == 'C')
		mlx_put_image_to_window((*status)->mlx_ptr, (*status)->win_ptr,
			(*status)->textures[2], width, height);
	if (c == '1')
		mlx_put_image_to_window((*status)->mlx_ptr, (*status)->win_ptr,
			(*status)->textures[3], width, height);
	if (c == 'E')
		mlx_put_image_to_window((*status)->mlx_ptr, (*status)->win_ptr,
			(*status)->textures[4], width, height);
}

/* window printer
 *
 * this function is the one responsible for locating the X & Y axis
 * and use that while sending the character of the map.*/
void	populate_window(t_objects **status)
{
	int	i;
	int	j;
	int	width;
	int	height;

	i = -1;
	height = 0;
	while ((*status)->map[++i])
	{
		j = -1;
		width = 0;
		while ((*status)->map[i][++j])
		{
			sort_populate((*status)->map[i][j], width, height, status);
			width += 32;
		}
		height += 32;
	}
}