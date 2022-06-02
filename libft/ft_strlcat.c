/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:38:57 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/02 15:11:44 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		j;

	j = 0;
	i = 0;
	while (dst[j] && j < dstsize)
		j++;
	while (src[i] && j + i + 1 < dstsize)
	{
		dst[j + i] = src[i];
		i++;
	}
	if (j < dstsize)
		dst[j + i] = '\0';
	return (j + ft_strlen(src));
}
