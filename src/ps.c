/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 10:17:40 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/24 10:19:48 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_pb(t_data *main_data)
{
	int	temp;
	int	n;

	n = 0;
	if (main_data->sep < 2)
		return ;
	temp = main_data->stack[0];
	main_data->sep -= 1;
	while (n < main_data->sep)
	{
		main_data->stack[n] = main_data->stack[n + 1];
		n++;
	}
	main_data->stack[main_data->sep] = temp;
	ft_printf("pb\n");
}

void	move_pa(t_data *main_data)
{
	int	temp;
	int	n;

	n = main_data->sep;
	if (main_data->sep == main_data->len)
		return ;
	temp = main_data->stack[main_data->sep];
	main_data->sep += 1;
	while (n > 0)
	{
		main_data->stack[n] = main_data->stack[n - 1];
		n--;
	}
	main_data->stack[0] = temp;
	ft_printf("pa\n");
}

void	move_sa(t_data *main_data)
{
	int	temp;

	temp = main_data->stack[0];
	main_data->stack[0] = main_data->stack[1];
	main_data->stack[1] = temp;
	ft_printf("sa\n");
}
