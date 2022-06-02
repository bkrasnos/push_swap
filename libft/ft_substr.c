/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:41:34 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/02 09:54:32 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new_string;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	new_string = (char *)malloc(sizeof(char) * len + 1);
	if (!new_string)
		return (NULL);
	new_string[len] = '\0';
	while (len-- && s[start])
		new_string[i++] = s[start++];
	return (new_string);
}
