/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_map_template.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 03:16:10 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/12 03:16:11 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

int	is0(char c)
{
	if (c == '0')
		return (1);
	return (0);
}

int	ise(char c, t_objects *status)
{
	if (c == 'E')
	{
		status->exit++;
		return (1);
	}
	return (0);
}

int	isc(char c, t_objects *status)
{
	if (c == 'C')
	{
		status->collectible++;
		return (1);
	}
	return (0);
}

int	isp(char c, t_objects *status)
{
	if (c == 'P')
	{
		status->player++;
		return (1);
	}
	return (0);
}

int	is1(char c)
{
	if (c == '1')
		return (1);
	return (0);
}
