/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strn_equal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:22:40 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/02 15:20:58 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strn_equal(char const *s1, char const *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	if (!(ft_strncmp(s1, s2, n)))
		return (1);
	return (0);
}
