/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:54:38 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/17 18:17:24 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	key_press(int keycode, t_objects **status)
{
	if (keycode == K_A)
		move_left(status);
	else if (keycode == K_S)
		move_down(status);
	else if (keycode == K_D)
		move_right(status);
	else if (keycode == K_W)
		move_north(status);
	else if (keycode == KEY_ESC)
	{
		mlx_destroy_window((*status)->mlx_ptr, (*status)->win_ptr);
		exit(0);
	}
	return (0);
}
