/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:22:37 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/02 15:20:25 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	char	*cdst;

	cdst = dst;
	while (len--)
	{
		if (*src)
			*cdst++ = *src++;
		else
			*cdst++ = '\0';
	}
	return (dst);
}
