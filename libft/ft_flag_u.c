/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:45:57 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/23 12:09:46 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include "libft.h"

static void	ft_putnbrr(unsigned int n, int *nb)
{
	char			c;

	if (n > 9)
		ft_putnbrr(n / 10, nb);
	n %= 10;
	c = n + '0';
	*nb = *nb + write(1, &c, 1);
}

void	ft_flag_u(va_list args, int *nb)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	ft_putnbrr(n, nb);
}
