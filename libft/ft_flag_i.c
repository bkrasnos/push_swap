/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_i.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:45:51 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/20 11:42:26 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(int n, int *nb)
{
	unsigned int	t;
	char			c;

	if (n < 0)
	{
		t = -n;
		*nb = *nb + write(1, "-", 1);
	}
	else
		t = n;
	if (t > 9)
		ft_putnbr(t / 10, nb);
	t %= 10;
	c = t + '0';
	*nb = *nb + write(1, &c, 1);
}

void	ft_flag_i(va_list args, int *nb)
{
	int	n;

	n = va_arg(args, int);
	ft_putnbr(n, nb);
}
