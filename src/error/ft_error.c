/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 03:16:59 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/12 03:16:59 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	ft_error(int i)
{
	if (i == 1)
		ft_putstr_fd("Error\n", 2);
	if (i == 2)
		ft_putstr_fd("Malloc failed", 2);
	if (i == 3)
		ft_putstr_fd("Incorrect Map", 2);
	if (i == 4)
		ft_putstr_fd("Read error", 2);
	if (i == 5)
		ft_putstr_fd("Invalid file", 2);
	exit(1);
}
