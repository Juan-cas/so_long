/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   append.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juan-cas <juan-cas@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 09:22:06 by juan-cas          #+#    #+#             */
/*   Updated: 2024/04/12 03:15:58 by juan-cas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

char	*append(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1)
		return (NULL);
	i = -1;
	j = 0;
	s3 = (char *)malloc(((ft_strlen(s1) + ft_strlen(s2)) * sizeof(char)) + 1);
	if (!s3)
		return (free(s1), s1 = NULL, free(s2), s2 = NULL, NULL);
	while (s1[++i])
		s3[i] = s1[i];
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	free(s1);
	free(s2);
	s1 = NULL;
	s2 = NULL;
	return (s3);
}
