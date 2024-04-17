/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_map_template.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 03:16:10 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/14 00:13:19 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"
/*this function checks if the character is '0' -> (road)*/
int	is0(char c)
{
	if (c == '0')
		return (1);
	return (0);
}
/*this function checks if the character is 'E' -> (exit)*/
int	ise(char c, t_objects *status)
{
	if (c == 'E')
	{
		status->exit++;
		return (1);
	}
	return (0);
}
/*this function checks if the character is 'C' -> (collectible)*/
int	isc(char c, t_objects *status)
{
	if (c == 'C')
	{
		status->collectible++;
		return (1);
	}
	return (0);
}
/*this function checks if the character is 'P' -> (player)*/
int	isp(char c, t_objects *status)
{
	if (c == 'P')
	{
		status->player++;
		return (1);
	}
	return (0);
}
/*this function checks if the character is '1' -> (wall)*/
int	is1(char c)
{
	if (c == '1')
		return (1);
	return (0);
}
