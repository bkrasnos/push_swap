/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 11:38:30 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/04/15 10:12:34 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		++i;
	}
}

// void	ft_to_lowercase(unsigned int i, char *ch)
// {
// 	printf("s[%d] is %c\n", i, ch[0]);
// 	if (ch[0] >= 65 && ch[0] <= 90)
// 		ch[0] = ch[0] + 32;
// }

// int	main(void)
// {
// 	char	s[] = "hELLO WORLD!";
// 	// char	*s2;

// 	printf("Initial str is '%s'\n", s);
// 	ft_striteri(s, &ft_to_lowercase);
// 	printf("Transofrmed str is '%s'\n", s);
// 	return (0);
// }