/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 18:54:38 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/12 03:13:45 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

static void	move_north(t_objects **status, size_t flag)
{
	if ((*status)->map[(*status)->py_coord - 1][(*status)->px_coord] != '1')
	{
		if ((*status)->map[(*status)->py_coord - 1][(*status)->px_coord] == 'C')
		{
			(*status)->map[(*status)->py_coord - 1][(*status)->px_coord] = 'P';
			(*status)->map[(*status)->py_coord][(*status)->px_coord] = '0';
			(*status)->py_coord -= 1;
 			put_floor(status, (*status)->px_coord * 32, (*status)->py_coord * 32);
			(*status)->collectible--;
		}
		else if ((*status)->map[(*status)->py_coord
			- 1][(*status)->px_coord] == '0')
		{
			(*status)->map[(*status)->py_coord - 1][(*status)->px_coord] = 'P';
			(*status)->map[(*status)->py_coord][(*status)->px_coord] = '0';
			(*status)->py_coord -= 1;
    }
		else if ((*status)->map[(*status)->py_coord
			- 1][(*status)->px_coord] == 'E' && (*status)->collectible == flag)
			exit(0);
    else if ((*status)->map[(*status)->py_coord
			- 1][(*status)->px_coord] == 'E' && (*status)->collectible != flag)
			return ;

		populate_window(status);
	}
}

static void	move_left(t_objects **status, size_t flag)
{
	if ((*status)->map[(*status)->py_coord][(*status)->px_coord - 1] != '1')
	{
		if ((*status)->map[(*status)->py_coord][(*status)->px_coord - 1] == 'C')
		{
			(*status)->map[(*status)->py_coord][(*status)->px_coord - 1] = 'P';
			(*status)->map[(*status)->py_coord][(*status)->px_coord] = '0';
			(*status)->px_coord -= 1;
			put_floor(status, (*status)->px_coord * 32, (*status)->py_coord * 32);
      (*status)->collectible--;
		}
		else if ((*status)->map[(*status)->py_coord][(*status)->px_coord
			- 1] == '0')
		{
			(*status)->map[(*status)->py_coord][(*status)->px_coord - 1] = 'P';
			(*status)->map[(*status)->py_coord][(*status)->px_coord] = '0';
      (*status)->px_coord -= 1;
    }
		else if ((*status)->map[(*status)->py_coord]
      [(*status)->px_coord - 1] == 'E' && (*status)->collectible == flag)
			exit(0);
    else if ((*status)->map[(*status)->py_coord][(*status)->px_coord
			- 1] == 'E' && (*status)->collectible != flag)
			return ;
		populate_window(status);
	}
}

static void	move_right(t_objects **status, size_t flag)
{
	if ((*status)->map[(*status)->py_coord][(*status)->px_coord + 1] != '1')
	{
		if ((*status)->map[(*status)->py_coord][(*status)->px_coord + 1] == 'C')
		{
			(*status)->map[(*status)->py_coord][(*status)->px_coord + 1] = 'P';
			(*status)->map[(*status)->py_coord][(*status)->px_coord] = '0';
			(*status)->px_coord += 1;
			put_floor(status, (*status)->px_coord * 32, (*status)->py_coord * 32);
      (*status)->collectible--;
    }
		else if ((*status)->map[(*status)->py_coord][(*status)->px_coord
			+ 1] == '0')
		{
			(*status)->map[(*status)->py_coord][(*status)->px_coord + 1] = 'P';
			(*status)->map[(*status)->py_coord][(*status)->px_coord] = '0';
			(*status)->px_coord += 1;
		}
		else if ((*status)->map[(*status)->py_coord]
      [(*status)->px_coord + 1] == 'E' && (*status)->collectible == flag)
			exit(0);
    else if ((*status)->map[(*status)->py_coord][(*status)->px_coord
			+ 1] == 'E' && (*status)->collectible != flag)
			return ;
		populate_window(status);
	}
}

static void	move_down(t_objects **status, size_t flag)
{
	if ((*status)->map[(*status)->py_coord + 1][(*status)->px_coord] != '1')
	{
		if ((*status)->map[(*status)->py_coord + 1][(*status)->px_coord] == 'C')
		{
			(*status)->map[(*status)->py_coord + 1][(*status)->px_coord] = 'P';
			(*status)->map[(*status)->py_coord][(*status)->px_coord] = '0';
      (*status)->py_coord += 1;
			put_floor(status, (*status)->px_coord * 32, (*status)->py_coord * 32);
      (*status)->collectible--;
		}
		else if ((*status)->map[(*status)->py_coord
			+ 1][(*status)->px_coord] == '0')
		{
			(*status)->map[(*status)->py_coord + 1][(*status)->px_coord] = 'P';
			(*status)->map[(*status)->py_coord][(*status)->px_coord] = '0';
			(*status)->py_coord += 1;
		}
		else if ((*status)->map[(*status)->py_coord
			+ 1][(*status)->px_coord] == 'E' && (*status)->collectible == flag)
			exit(0);
    else if ((*status)->map[(*status)->py_coord
			+ 1][(*status)->px_coord] == 'E' && (*status)->collectible != flag)
			return ;
		populate_window(status);
	}
}

int	key_press(int keycode, t_objects **status)
{
  size_t flag;
  static int steps = -1;

  flag = 0;
    // step_printer(&steps);
	if (keycode == K_A)
		move_left(status, flag);
	else if (keycode == K_S)
		move_down(status, flag);
	else if (keycode == K_D)
		move_right(status, flag);
	else if (keycode == K_W)
		move_north(status, flag);
	else if (keycode == KEY_ESC)
	{
		mlx_destroy_window((*status)->mlx_ptr, (*status)->win_ptr);
		exit(0);
	}
	else if (keycode == ARROW_KEY_LEFT)
		move_left(status, flag);
	else if (keycode == ARROW_KEY_RIGHT)
		move_right(status, flag);
	else if (keycode == ARROW_KEY_UP)
		move_north(status, flag);
	else if (keycode == ARROW_KEY_DOWN)
		move_down(status, flag);
	return (0);
}
