/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:54:38 by juan-cas          #+#    #+#             */
/*   Updated: 2024/07/14 17:22:46 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

/**
 * @brief handles movement
 * This function takes signals in order to move the character letter through
 * the map
 * @param keycode the code for the operating system of the key being pressed.
 * @param status the structure that contains the information of the map.
 */
int	key_press(int keycode, t_objects **status)
{
	if (keycode == XK_A || keycode == XK_Left)
		move_left(status);
	else if (keycode == XK_S || keycode == XK_Down)
		move_down(status);
	else if (keycode == XK_D || keycode == XK_Right)
		move_right(status);
	else if (keycode == XK_W || keycode == XK_Up)
		move_north(status);
	else if (keycode == XK_Escape)
	{
		ft_putstr_fd("aww, dont give up my dudette, you can do it!", 1);
		mlx_destroy_window((*status)->mlx_ptr, (*status)->win_ptr);
		exit(0);
	}
	return (0);
}
