/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:35:42 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/02 14:28:14 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbrs(long n, char *str, int *i)
{
	if (n > 9)
	{
		ft_putnbrs(n / 10, str, i);
		ft_putnbrs(n % 10, str, i);
	}
	else
	{
		str[(*i)] = n + '0';
		++(*i);
	}
}

size_t	ft_nbrlen(long long n)
{
	size_t	i;

	i = 1;
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	nbr;

	nbr = n;
	str = malloc(sizeof(char) * (ft_nbrlen(nbr) + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	if (nbr < 0)
	{
		str[i] = '-';
		nbr *= -1;
		i++;
	}
	ft_putnbrs(nbr, str, &i);
	str[i] = '\0';
	return (str);
}
