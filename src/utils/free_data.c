/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:57:07 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/02 20:57:07 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../solong.h"

void free_coords(t_objects **nodes)
{
	t_objects *prev;
	t_objects *temp;

	temp = *nodes;
	prev = *nodes;
	while (temp)
	{
		temp = temp->next;
		free(prev);
		prev = temp;
	}
}