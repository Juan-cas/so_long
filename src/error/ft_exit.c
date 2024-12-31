/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 02:31:48 by juan-cas          #+#    #+#             */
/*   Updated: 2024/11/21 03:53:47 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

/**
 * @brief closes the windows in case the player clicks the X in the window.
 * @param status structure containing the data for the game to work correctly.
 */
int	ft_exit(t_objects **status)
{
	mlx_destroy_window((*status)->mlx_ptr, (*status)->win_ptr);
	printf("don't give up my dudette, you can do it just try again!\n");
	exit(EXIT_SUCCESS);
}
