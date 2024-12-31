/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_map_template.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 03:16:10 by juan-cas          #+#    #+#             */
/*   Updated: 2024/11/21 00:32:52 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

/**
 * @brief checks if character is 0 -> road
 */
int	is0(char c)
{
	if (c == '0')
		return (1);
	return (0);
}

/**
 * @brief checks if character is E -> exit
 */
int	ise(char c, t_objects *status)
{
	if (c == 'E')
	{
		status->exit++;
		return (1);
	}
	return (0);
}

/**
 * @brief checks if character is C -> Collectible
 */
int	isc(char c, t_objects *status)
{
	if (c == 'C')
	{
		status->collectible++;
		return (1);
	}
	return (0);
}

/**
 * @brief checks if character is P -> Player
 */
int	isp(char c, t_objects *status)
{
	if (c == 'P')
	{
		status->player++;
		return (1);
	}
	return (0);
}

/**
 * @brief checks if character is 1 -> Wall
 */
int	is1(char c)
{
	if (c == '1')
		return (1);
	return (0);
}
