/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:45:47 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/20 11:42:19 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_flag_c(va_list args, int *nb)
{
	unsigned char	c;

	c = (unsigned char)va_arg(args, int);
	write(1, &c, 1);
	*nb += 1;
}
