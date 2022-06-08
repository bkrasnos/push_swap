/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_output_string.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:34:47 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/08 09:14:05 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_shrink(int *width)
{
	if (*width > 0)
	{
		--(*width);
		return (1);
	}
	return (0);
}

void	ft_output_string(t_print *tab, char *str, int *a)
{
	if (!str)
	{
		ft_output_string(tab, "(null)", a);
		return ;
	}
	if (tab->dot >= 0 && tab->width && tab->width > tab->dot)
		tab->width -= tab->dot;
	else if (tab->dot >= 0 && tab->width && tab->width < tab->dot)
			tab->width = tab->dot - tab->width + 1;
	else
		tab->width -= ft_strlen(str);
	while (tab->zero && ft_shrink(&tab->width))
		ft_putcharr('0', a);
	while (!tab->zero && !tab->minus && ft_shrink(&tab->width))
		ft_putcharr(' ', a);
	while (*str != '\0')
	{
		if (tab->dot >= 0 && !(ft_shrink(&tab->dot)))
			break ;
		ft_putcharr(*str, a);
		++str;
	}
	while (tab->minus && ft_shrink(&tab->width))
		ft_putcharr(' ', a);
}
