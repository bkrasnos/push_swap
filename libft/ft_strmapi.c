/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:39:21 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/02 10:19:53 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char		*new_string;
	size_t		len;
	int			i;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	new_string = (char *)malloc(sizeof(char) * len + 1);
	if (!new_string)
		return (NULL);
	new_string[len] = '\0';
	i = -1;
	while (s[++i])
		new_string[i] = (*f)(i, s[i]);
	return (new_string);
}
