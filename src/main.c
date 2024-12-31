/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:57:50 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/20 04:36:14 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	main(int argc, char **argv)
{
	t_objects	*status;
	char		**map;
	int			fd;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error(5);
	if (read(fd, 0, 0) < 0)
		ft_error(4);
	status = malloc(sizeof(t_objects));
	if (!status)
		return (free(status), 1);
	status->next = NULL;
	map = init_parser(argv, &status, fd);
	solong(map, &status);
	matrix_clear(map);
	free(status);
	printf("all good");
	return (0);
}
