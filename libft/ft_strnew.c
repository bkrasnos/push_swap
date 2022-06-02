/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:22:43 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/02 09:58:08 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*new_string;

	new_string = (char *)malloc(sizeof(char) * size + 1);
	if (!new_string)
		return (NULL);
	ft_bzero(new_string, size + 1);
	return (new_string);
}
