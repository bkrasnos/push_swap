/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 11:46:10 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/23 09:15:53 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	check_two_arg(char *str)
{
	size_t	n;

	n = 0;
	if (ft_strlen(str) < 1
		|| (!ft_isdigit(str[0]) && str[0] != '-' && str[0] != '+'))
		return (0);
	if ((str[0] == '-' || str[0] == '+')
		&& (ft_strlen(str) < 2))
		return (0);
	while (str[n] && n < ft_strlen(str))
	{
		if ((str[n] == '-' || str[n] == '+')
			&& (!str[n + 1] || !ft_isdigit(str[n + 1])))
			return (0);
		if (!(str[n] == '-' || str[n] == '+' || ft_isdigit(str[n])))
			return (0);
		n++;
		while (str[n] && ft_isdigit(str[n]))
			n++;
		if (str[n] && str[n] != ' ' && str[n] != '\t')
			return (0);
		n++;
	}
	return (1);
}

static char	**stack_char(char **av, int ac)
{
	char	**data;
	int		n;

	n = 0;
	if (ac == 2)
	{
		data = ft_split(av[1], ' ');
		if (!data)
			return (NULL);
	}
	else
	{
		data = malloc(ac * sizeof(char *));
		if (!data)
			return (NULL);
		while (++n < ac)
		{
			data[n - 1] = ft_strdup(av[n]);
			if (!data[n - 1])
				data_free(data, 1);
		}
		data[n - 1] = NULL;
	}
	return (data);
}

static void	stack_init(t_data *main_data, char **data)
{
	int	n;
	int	i;

	n = main_data->len - 1;
	i = 0;
	main_data->stack = malloc(main_data->len * sizeof(int));
	if (!main_data->stack)
	{
		free(main_data);
		data_free(data, 1);
	}
	while (n > -1)
	{
		main_data->stack[i] = ft_atoi(data[n]);
		n--;
		i++;
	}
	data_free(data, 0);
}

void	stack_index(t_data *main_data)
{
	int	n;
	int	*new_stack;

	new_stack = malloc(main_data->len * sizeof(int));
	if (!new_stack)
		stack_free(main_data, 1);
	n = 0;
	get_max(main_data, new_stack);
	while (n < main_data->len - 1)
	{
		get_min(main_data, n, new_stack);
		n++;
	}
	free(main_data->stack);
	main_data->stack = new_stack;
}

t_data	*main_init(char **av, int ac)
{
	char	**data;
	t_data	*main_data;
	size_t	n;

	n = 0;
	data = stack_char(av, ac);
	if (!data || !check_atoi(data)
		|| !check_stack_double(data))
		stop_error();
	if (!data[0])
		data_free(data, 1);
	main_data = malloc(sizeof(t_data));
	if (!main_data)
		data_free(data, 1);
	main_data->len = 0;
	while (data[main_data->len])
		main_data->len += 1;
	main_data->sep = main_data->len;
	stack_init(main_data, data);
	stack_index(main_data);
	return (main_data);
}
