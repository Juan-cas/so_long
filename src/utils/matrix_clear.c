/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 03:30:20 by juan-cas          #+#    #+#             */
/*   Updated: 2024/03/30 03:30:20 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../solong.h"

void	matrix_clear(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
		free(matrix[i++]);
	free(matrix);
}