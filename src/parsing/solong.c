/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 23:51:02 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/17 02:36:54 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"
/* main program function it initiates the structure matrix the pointer to the
 * server, and the window, fills it with the sprites and keeps the mlxServer
 * in a loop waiting for the hooks*/
void	solong(char **map, t_objects **status)
{
	(*status)->mlx_ptr = mlx_init();
	if (!(*status)->mlx_ptr)
		ft_error(2);
	textures_init(status, map);
	(*status)->win_ptr = mlx_new_window((*status)->mlx_ptr, (*status)->winxsize,
			(*status)->winysize, "so_long");
	if (!(*status)->win_ptr)
		ft_error(2);
	populate_window(status);
	mlx_key_hook((*status)->win_ptr, &key_press, status);
	mlx_hook((*status)->win_ptr, 17, 1L << 2, &ft_exit, status);
	mlx_loop((*status)->mlx_ptr);
}