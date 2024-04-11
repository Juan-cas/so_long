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

  (*status)->mlx_ptr = mlx_init();
	if (!(*status)->mlx_ptr)
    ft_error(2);
	textures_init(status);
	(*status)->win_ptr = mlx_new_window((*status)->mlx_ptr, (*status)->winxsize, (*status)->winysize, "solong");
	if (!(*status)->win_ptr)
	    ft_error(2);
	populate_window(map, status);
  mlx_key_hook((*status)->win_ptr, &key_press, status);
	mlx_loop((*status)->mlx_ptr);
}
