/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 14:01:06 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/21 14:09:14 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	check_line(char *s, t_stock **a, t_stock **b)
{
	if (!ft_strcmp(s, "sa\n"))
		swap(a, NULL);
	else if (!ft_strcmp(s, "sb\n"))
		swap(b, NULL);
	else if (!ft_strcmp(s, "ss\n"))
	{
		swap(a, NULL);
		swap(b, NULL);
	}
	else if (!ft_strcmp(s, "pa\n"))
		push(b, a, NULL);
	else if (!ft_strcmp(s, "pb\n"))
		push(a, b, NULL);
	else if (!ft_strcmp(s, "ra\n"))
		rotate(a, NULL);
	else if (!ft_strcmp(s, "rb\n"))
		rotate(b, NULL);
	else
		return (0);
	return (1);
}

void	check_line_1(char *s, t_stock **a, t_stock **b)
{
	if (!ft_strcmp(s, "rr\n"))
	{
		rotate(a, NULL);
		rotate(b, NULL);
	}
	else if (!ft_strcmp(s, "rra\n"))
		reverse_rotate(a, NULL);
	else if (!ft_strcmp(s, "rrb\n"))
		reverse_rotate(b, NULL);
	else if (!ft_strcmp(s, "rrr\n"))
	{
		reverse_rotate(a, NULL);
		reverse_rotate(b, NULL);
	}
	else
	{
		free(s);
		s = NULL;
		free_error(*a, *b);
	}
}

void	get_stdin(t_stock **a, t_stock **b)
{
	char	*line;
	int		flag;

	line = get_next_line(0);
	while (line)
	{
		flag = check_line(line, a, b);
		if (!flag)
			check_line_1(line, a, b);
		if (!line)
			free_error(*a, *b);
		free(line);
		line = get_next_line(0);
	}
}
