/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 03:16:23 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/17 08:08:13 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

/**
 * @brief checks top and bottom walls
 * This function ensures that the top and bottom walls are made of 1
 * characters.
 */
int	line1(const char *line)
{
	int	i;

	i = 0;
	while (line[++i])
	{
		if (line[i] != '1')
			return (0);
	}
	return (1);
}
