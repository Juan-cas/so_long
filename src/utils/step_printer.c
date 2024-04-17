/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_printer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 22:51:31 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/17 08:01:24 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	step_printer(int i)
{
	ft_putstr_fd("the number of steps is: ", 1);
	ft_putnbr_fd(i, 1);
	write(1, "\n", 1);
}
