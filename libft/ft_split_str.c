/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 12:22:47 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/02 16:14:37 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_parts(const char *s, char c)
{
	int		count;
	int		in_substring;

	in_substring = 0;
	count = 0;
	while (*s)
	{
		if (in_substring == 1 && *s == c)
			in_substring = 0;
		if (in_substring == 0 && *s != c)
		{
			in_substring = 1;
			count++;
		}
		s++;
	}
	return (count);
}

static int	ft_wlen(const char *s, char c)
{
	int		len;

	len = 0;
	while (*s != c && *s)
	{
		len++;
		s++;
	}
	return (len);
}

char	**ft_split_str(char const *s, char c)
{
	char	**tab;
	int		nb_word;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	nb_word = ft_count_parts(s, c);
	tab = (char **)malloc(sizeof(char) * ft_count_parts(s, c) + 1);
	if (!tab)
		return (NULL);
	while (nb_word--)
	{
		while (*s == c && *s)
			s++;
		tab[i] = ft_substr(s, 0, ft_wlen(s, c));
		if (!tab[i])
			return (NULL);
		s = s + ft_wlen(s, c);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
