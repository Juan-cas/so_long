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

static void move_north(t_objects **status, size_t *i)
{
  if ((*status)->map[(*status)->py_coord - 1][(*status)->px_coord] == '1')
    return ;
  else if ((*status)->map[(*status)->py_coord - 1][(*status)->px_coord] == 'C')
  {
    (*status)->map[(*status)->py_coord - 1][(*status)->px_coord] = 'P';
    (*status)->map[(*status)->py_coord][(*status)->px_coord] = '0';
    (*status)->py_coord -= 1;
    (*i)++;
   populate_window(status); 
  }
  else if ((*status)->map[(*status)->py_coord - 1][(*status)->px_coord] == '0')
  {
    (*status)->map[(*status)->py_coord - 1][(*status)->px_coord] = 'P';
    (*status)->map[(*status)->py_coord][(*status)->px_coord] = '0';
    (*status)->py_coord -= 1;
   populate_window(status); 
  }
  else if ((*status)->map[(*status)->py_coord - 1][(*status)->px_coord] == 'E' \
   && i != &(*status)->collectible)
    return ;
  else
   exit(0); 
}

static void move_left(t_objects **status, size_t *i)
{
  if ((*status)->map[(*status)->py_coord][(*status)->px_coord - 1] == '1')
    return ;
  else if ((*status)->map[(*status)->py_coord][(*status)->px_coord - 1] == 'C')
  {
    (*status)->map[(*status)->py_coord][(*status)->px_coord - 1] = 'P';
    (*status)->map[(*status)->py_coord][(*status)->px_coord] = '0';
    (*status)->py_coord -= 1;
    (*i)++;
   populate_window(status); 
  }
  else if ((*status)->map[(*status)->py_coord - 1][(*status)->px_coord] == '0')
  {
    (*status)->map[(*status)->py_coord - 1][(*status)->px_coord] = 'P';
    (*status)->map[(*status)->py_coord][(*status)->px_coord] = '0';
    (*status)->py_coord -= 1;
   populate_window(status); 
  }
  else if ((*status)->map[(*status)->py_coord][(*status)->px_coord - 1] == 'E' \
   && i != &(*status)->collectible)
    return ;
  else
   exit(0);

}

static void move_right(t_objects **status, size_t *i)
{
  if ((*status)->map[(*status)->py_coord][(*status)->px_coord + 1] == '1')
    return ;
  else if ((*status)->map[(*status)->py_coord][(*status)->px_coord + 1] == 'C')
  {
    (*status)->map[(*status)->py_coord][(*status)->px_coord + 1] = 'P';
    (*status)->map[(*status)->py_coord][(*status)->px_coord] = '0';
    (*status)->px_coord += 1;
    (*i)++;
   populate_window(status); 
  }
  else if ((*status)->map[(*status)->py_coord - 1][(*status)->px_coord] == '0')
  {
    (*status)->map[(*status)->py_coord][(*status)->px_coord + 1] = 'P';
    (*status)->map[(*status)->py_coord][(*status)->px_coord] = '0';
    (*status)->px_coord += 1;
   populate_window(status); 
  }
  else if ((*status)->map[(*status)->py_coord][(*status)->px_coord - 1] == 'E' \
   && i != &(*status)->collectible)
    return ;
  else
   exit(0);
}

static void move_down(t_objects **status, size_t *i)
{
  if ((*status)->map[(*status)->py_coord + 1][(*status)->px_coord] == '1')
    return ;
  else if ((*status)->map[(*status)->py_coord + 1][(*status)->px_coord] == 'C')
  {
    (*status)->map[(*status)->py_coord + 1][(*status)->px_coord] = 'P';
    (*status)->map[(*status)->py_coord][(*status)->px_coord] = '0';
    (*status)->py_coord += 1;
    (*i)++;
   populate_window(status); 
  }
  else if ((*status)->map[(*status)->py_coord + 1][(*status)->px_coord] == '0')
  {
    (*status)->map[(*status)->py_coord - 1][(*status)->px_coord] = 'P';
    (*status)->map[(*status)->py_coord][(*status)->px_coord] = '0';
    (*status)->py_coord -= 1;
   populate_window(status); 
  }
  else if ((*status)->map[(*status)->py_coord + 1][(*status)->px_coord] == 'E' \
   && i != &(*status)->collectible)
    return ;
  else
   exit(0);
}


int key_press(int keycode, t_objects **status)  
{
	static size_t i = 0;

  if (keycode == K_A)
	  move_left(status, &i);	
  else if (keycode == K_S)
    move_down(status, &i);
  else if (keycode == K_D)
    move_right(status, &i);
  else if (keycode == K_W)
    move_north(status, &i);
  else if (keycode == KEY_ESC)
  {
    mlx_destroy_window((*status)->mlx_ptr, (*status)->win_ptr);
    exit(0);
  }
  else if (keycode == ARROW_KEY_LEFT)
    move_left(status, &i);
  else if (keycode == ARROW_KEY_RIGHT)
    move_right(status, &i);  
  else if (keycode == ARROW_KEY_UP)
    move_north(status, &i);
  else if (keycode == ARROW_KEY_DOWN)
    move_down(status, &i);
	return (0);
}
