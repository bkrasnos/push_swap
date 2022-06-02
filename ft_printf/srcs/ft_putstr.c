/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:35:05 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/02 17:32:41 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_pputstr(char *str, int *a)
{
	int	i;

	if (!str)
	{
		ft_pputstr("NULL", a);
		return ;
	}
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		++i;
		++(*a);
	}
}
