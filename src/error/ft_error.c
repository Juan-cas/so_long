/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 03:16:59 by juan-cas          #+#    #+#             */
/*   Updated: 2024/11/21 03:53:30 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

/**
 * @brief print an error from a list of possible errors.
 * then exits the program.
 * @param i describes in an int the type of error encountered.
 *
 */
void	ft_error(int i)
{
	if (i == 1)
		ft_putstr_fd("Error\n", 2);
	if (i == 2)
		ft_putstr_fd("Error\nMalloc failed\n", 2);
	if (i == 3)
		ft_putstr_fd("Error\nIncorrect Map\n", 2);
	if (i == 4)
		ft_putstr_fd("Error\nRead error\n", 2);
	if (i == 5)
		ft_putstr_fd("Error\nInvalid file\n", 2);
	if (i == 6)
		ft_putstr_fd("Error\nCheck Image Permisions\n", 2);
	if (i == 7)
		ft_putstr_fd("Error\nEmpty map\n", 2);
	exit(1);
}
