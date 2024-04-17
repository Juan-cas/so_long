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

/*function to check the first and the last lines of a file, to check if its
 * only walls*/
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
