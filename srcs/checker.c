/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 17:26:34 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/06 15:49:18 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	define(char *line, t_list **list_a, t_list **list_b)
{
	if (!(ft_strcmp(line, "ra")))
		ra(list_a, list_b, 0);
	else if (!(ft_strcmp(line, "rb")))
		rb(list_a, list_b, 0);
	else if (!(ft_strcmp(line, "rr")))
		rr(list_a, list_b, 0);
	else if (!(ft_strcmp(line, "sa")))
		sa(*list_a, *list_b, 0);
	else if (!(ft_strcmp(line, "sb")))
		sb(*list_b, *list_b, 0);
	else if (!(ft_strcmp(line, "ss")))
		ss(*list_a, *list_b, 0);
	else if (!(ft_strcmp(line, "rra")))
		rra(list_a, list_b, 0);
	else if (!(ft_strcmp(line, "rrb")))
		rrb(list_a, list_b, 0);
	else if (!(ft_strcmp(line, "rrr")))
		rrr(list_a, list_b, 0);
	else if (!(ft_strcmp(line, "pa")))
		pa(list_a, list_b, 0);
	else if (!(ft_strcmp(line, "pb")))
		pb(list_a, list_b, 0);
	else
		return (0);
	return (1);
}

int	checker(t_list **list_a, t_list **list_b)
{
	int		ret;
	char	*line;

	ret = get_next_line(0, &line);
	while (ret > 0)
	{
		if (ret == -1)
		{
			free(line);
			return (0);
		}
		if (!(define(line, list_a, list_b)))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		ret;
	t_info	*info;
	t_list	*list_a;
	t_list	*list_b;

	if (ac < 2 || (ac < 3 && !ft_strcmp(av[1], "-v")))
		return (0);
	info = malloc(sizeof(t_info));
	if (!info)
		return (0);
	list_a = create_list(ac, av, &info);
	if (!list_a)
		return (free_all(list_a, info));
	ret = checker(&list_a, &list_b);
	if (ret == 0)
		return (free_all(list_a, info));
	if (list_a && is_sort(list_a) && !list_b)
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	if (list_b)
		free_list(list_b);
	free_list(list_a);
	free(info);
	return (0);
}
