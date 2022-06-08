/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 11:38:54 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/06 15:12:11 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_algorithm(t_list **list_a, t_info *info)
{
	if (find_size(*list_a) > 8)
	{
		if (!(solution(list_a, info)))
			return (0);
	}
	else
		fast_solution(list_a, info);
	if (info->print == 2)
	{
		ft_printf("\x1b[36mSort stack : \n\n");
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*list_a;
	t_info	*info;

	if (ac < 2 || (ac < 3 && !ft_strcmp(av[1], "-v")))
		return (0);
	info = malloc(sizeof(t_info));
	if (!info)
		return (0);
	info->print = 1;
	list_a = create_list(ac, av, &info);
	if (!list_a)
	{
		free(info);
		return (write(2, "Error\n", 6));
	}
	if (info->print == 2)
	{
		ft_printf("\x1b[36m\nStart Stack : \n\n");
	}
	find_algorithm(&list_a, info);
	free_list(list_a);
	free(info);
	return (0);
}
