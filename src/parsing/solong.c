/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:51:02 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/08 20:31:42 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"



void solong(char **map, t_objects **status)
{
	t_data *data;

	data = malloc(sizeof(t_data));
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return ;
	textures_init(data, map);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->winxsize, data->winysize, "solong");
	if (!data->win_ptr)
	{
		free(data->mlx_ptr);
		return ;
	}
	populate_window(map, &data);
  mlx_key_hook(data->win_ptr, &key_press, &data);
  // mlx_loop_hook(data->mlx_ptr, 
	mlx_loop(data->mlx_ptr);
}
