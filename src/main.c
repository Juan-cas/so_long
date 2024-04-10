/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:57:50 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/07 20:44:45 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "solong.h"


int main (int argc, char **argv)
{
  if (argc != 2)
    return (0);
  t_objects	*status;
  char		**map;

  status = malloc(sizeof(t_objects));
  if (!status)
	  return (free(status), 1);
  status->next = NULL;

  map = init_parser(argv, &status);
  solong(map);
  matrix_clear(map);
  free(status);
  printf("all good");
  return (0);
}
