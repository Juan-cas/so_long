/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 02:31:48 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/17 08:17:24 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

/* will show a message in the terminal and exit the process */
int	ft_exit(t_objects **status)
{
	mlx_destroy_window((*status)->mlx_ptr, (*status)->win_ptr);
	printf("don't give up my dudette, you can do it just try again!\n");
	exit(EXIT_SUCCESS);
}
