/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:54:38 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/08 19:41:43 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int key_press(int keycode, t_objects **status)  
{
	
  if (keycode == K_A)
		printf("A key pressed\n");
  else if (keycode == K_S)
		printf("S key pressed\n");
  else if (keycode == K_D)
		printf("D key pressed\n");
  else if (keycode == K_W)
		printf("W key pressed\n");
  else if (keycode == KEY_ESC)
    mlx_destroy_window((*status)->mlx_ptr, (*status)->win_ptr);
  else if (keycode == ARROW_KEY_LEFT)
		printf("Left arrow key pressed\n");
  else if (keycode == ARROW_KEY_RIGHT)
		printf("Right arrow key pressed\n");
  else if (keycode == ARROW_KEY_UP)
		printf("Up arrow key pressed\n");
  else if (keycode == ARROW_KEY_DOWN)
		printf("Down arrow key pressed\n");
	return (0);
}
