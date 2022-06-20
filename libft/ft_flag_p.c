/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:45:53 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/20 09:46:58 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_hex(unsigned long int n, int *nb)
{
	unsigned long int	t;
	char				c;
	char				*str;

	str = "0123456789abcdef";
	t = n;
	if (t > 15)
		ft_putnbr_hex(t / 16, nb);
	t %= 16;
	c = str[t];
	*nb = *nb + write(1, &c, 1);
}

void	ft_flag_p(va_list args, int *nb)
{
	unsigned long int	n;

	*nb = *nb + write(1, "0x", 2);
	n = va_arg(args, unsigned long int);
	ft_putnbr_hex(n, nb);
}
