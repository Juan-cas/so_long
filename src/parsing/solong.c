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

int on_destroy(t_data *data)
{
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	exit(0);
}

int on_keypress(int keysym, t_data *data)
{
	(void)data;
	printf("Pressed key: %d\\n", keysym);
	return (0);
}

void solong(char **map)
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
//	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &key_press, data->mlx_ptr);
	mlx_loop(data->mlx_ptr);
}
