/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:57:50 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/12 03:16:49 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int argc, char **argv)
{
	t_objects	*status;
	char		**map;

	if (argc != 2)
		return (0);
	status = malloc(sizeof(t_objects));
	if (!status)
		return (free(status), 1);
	status->next = NULL;
	map = init_parser(argv, &status);
	solong(map, &status);
	matrix_clear(map);
	free(status);
	printf("all good");
	return (0);
}
