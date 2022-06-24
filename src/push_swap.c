/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:46:16 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/24 10:19:51 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_data *main_data)
{
	int		i;
	size_t	n;

	if (is_sorted(main_data))
		return ;
	n = 0;
	while (!is_sorted(main_data))
	{
		i = 0;
		while (i < main_data->len)
		{
			if (!((main_data->stack[0] >> n) & 1))
				move_pb(main_data);
			else if (main_data->sep < 2)
				break ;
			else
				move_ra(main_data);
			i++;
		}
		while (main_data->sep < main_data->len)
			move_pa(main_data);
		n++;
	}
}

static void	small_three(t_data *main_data)
{
	if (main_data->stack[0] == 1 && main_data->stack[1] == 0
		&& main_data->stack[2] == 2)
		move_sa(main_data);
	else if (main_data->stack[0] == 0 && main_data->stack[1] == 2
		&& main_data->stack[2] == 1)
	{
		move_rra(main_data);
		move_sa(main_data);
	}
	else if (main_data->stack[0] == 2 && main_data->stack[1] == 0
		&& main_data->stack[2] == 1)
		move_ra(main_data);
	else if (main_data->stack[0] == 1 && main_data->stack[1] == 2
		&& main_data->stack[2] == 0)
		move_rra(main_data);
	else if (main_data->stack[0] == 2 && main_data->stack[1] == 1
		&& main_data->stack[2] == 0)
	{
		move_ra(main_data);
		move_sa(main_data);
	}
}

static int	small_four_easy(t_data *main_data)
{
	if (main_data->stack[0] == 1 && main_data->stack[1] == 0
		&& main_data->stack[2] == 2 && main_data->stack[3] == 3)
	{
		move_sa(main_data);
		return (1);
	}
	else if (main_data->stack[0] == 1 && main_data->stack[1] == 2
		&& main_data->stack[2] == 3 && main_data->stack[3] == 0)
	{
		move_rra(main_data);
		return (1);
	}
	else if (main_data->stack[0] == 3 && main_data->stack[1] == 0
		&& main_data->stack[2] == 1 && main_data->stack[3] == 2)
	{
		move_ra(main_data);
		return (1);
	}
	else
		return (0);
}

void	small_four(t_data *main_data)
{
	int	n;

	if (small_four_easy(main_data))
		return ;
	if (main_data->stack[1] == 0)
		move_ra(main_data);
	else if (main_data->stack[2] == 0)
	{
		move_ra(main_data);
		move_ra(main_data);
	}
	else if (main_data->stack[3] == 0)
		move_rra(main_data);
	move_pb(main_data);
	n = 0;
	while (n < main_data->sep)
	{
		main_data->stack[n] -= 1;
		n++;
	}
	small_three(main_data);
	move_pa(main_data);
}

void	small_push_swap(t_data *main_data)
{
	if (is_sorted(main_data))
		return ;
	else if (main_data->sep == 2 && main_data->stack[0] > main_data->stack[1])
		move_ra(main_data);
	else if (main_data->sep == 3)
		small_three(main_data);
	else if (main_data->sep == 4)
		small_four(main_data);
	else
		small_five(main_data);
}
