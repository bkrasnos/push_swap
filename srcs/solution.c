/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:14:52 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/06 15:27:47 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_max(t_list **list_a, t_list **list_b, int m, t_info *info)
{
	int	f;

	f = 0;
	if ((*list_b)->content < m)
	{
		while ((*list_b)->content != m)
		{
			if ((*list_b)->next->content == m)
			{
				sb(*list_a, *list_b, info->print);
				pa(list_a, list_b, info->print);
				f = 1;
				break ;
			}
			if (info->flags == 1)
				rb(list_a, list_b, info->print);
			else
				rrb(list_a, list_b, info->print);
		}
	}
	if (!f)
		pa(list_a, list_b, info->print);
}

static void	push_a(t_list **list_a, t_list **list_b, t_info *info, t_data *data)
{
	while (info->size_b)
	{
		data->flags_a = 0;
		data->flags_b = 0;
		data->max_b = find_max(*list_b, -2147483648);
		data->max_a = find_max(*list_b, data->max_b);
		data->pos_a = find_pos(data->max_b, *list_b);
		if (data->pos_a < info->size_b / 2)
			data->flags_a = 1;
		data->pos_b = find_pos(data->max_a, *list_b);
		if (data->max_a != -2147483648 && data->pos_b < info->size_b / 2)
			data->flags_b = 1;
		info->flags = data->flags_a;
		if (data->max_a != -2147483648 && data->flags_a == data->flags_b
			&& ((data->pos_a > data->pos_b && data->flags_a)
				|| (data->pos_a < data->pos_b && !data->flags_a)))
		{
			push_max(list_a, list_b, data->max_a, info);
			push_max(list_a, list_b, data->max_b, info);
			sa(*list_a, *list_b, info->print);
			info->size_b--;
		}
		else
			push_max(list_a, list_b, data->max_b, info);
		info->size_b--;
	}
}

static void	optimised_rotation(int tmp, t_list **list_a, t_list **list_b,
				t_info **info)
{
	while (tmp && (*info)->size_a > 2)
	{
		if ((*list_a)->content <= (*info)->pivot)
		{
			pb(list_a, list_b, (*info)->print);
			if ((*list_b)->content < find_middle(*list_b, (*info)->size_b)
				&& (*info)->size_b > 1)
			{
				if ((*list_a)->content > (*info)->pivot)
					rr(list_a, list_b, (*info)->print);
				else
					rb(list_a, list_b, (*info)->print);
			}
			(*info)->size_b++;
			(*info)->size_a--;
		}
		else
			ra(list_a, list_b, (*info)->print);
		tmp--;
	}
}

int	resolve(t_list **list_a, t_info *info)
{
	int		tmp;
	t_data	*data;
	t_list	*list_b;

	list_b = 0;
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	if (is_sort(*list_a))
		return (1);
	info->size_a = find_size(*list_a);
	info->size_b = 0;
	while (info->size_a > 2)
	{
		info->pivot = find_middle(*list_a, info->size_a);
		tmp = info->size_a;
		optimised_rotation(tmp, list_a, &list_b, &info);
	}
	pb(list_a, &list_b, info->print);
	pb(list_a, &list_b, info->print);
	info->size_b += 2;
	push_a(list_a, &list_b, info, data);
	free(data);
	return (1);
}
