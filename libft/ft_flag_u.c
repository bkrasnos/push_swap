/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 09:45:57 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/20 11:42:36 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_flag_s(va_list args, int *nb)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
		*nb = *nb + write(1, "(null)", 6);
	else
		*nb = *nb + write(1, str, ft_strlen(str));
}
