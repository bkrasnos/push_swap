/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:46:18 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/20 11:52:19 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	move_ra(t_data *main_data)
{
	int	temp;
	int	n;

	n = 0;
	if (main_data->sep < 2)
		return ;
	temp = main_data->stack[0];
	while (n < main_data->sep - 1)
	{
		main_data->stack[n] = main_data->stack[n + 1];
		n++;
	}
	main_data->stack[main_data->sep - 1] = temp;
	ft_printf("ra\n");
}

void	move_rra(t_data *main_data)
{
	int	temp;
	int	n;

	n = main_data->sep - 1;
	if (main_data->sep < 2)
		return ;
	temp = main_data->stack[n];
	while (n > 0)
	{
		main_data->stack[n] = main_data->stack[n - 1];
		n--;
	}
	main_data->stack[0] = temp;
	ft_printf("rra\n");
}
