/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:18:28 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/09 13:27:21 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_data
{
	int		*stack;
	int		sep;
	int		len;
	char	*moves;
}	t_data;

void	push_swap(t_data *main_data);
void	small_push_swap(t_data *main_data);
int		check_argv(char **av, int ac);
void	data_free(char **data, int state);
int		check_atoi(char **data);
t_data	*main_init(char **av, int ac);
int		check_atoi(char **data);
int		check_stack_double(char **data);
void	stop_error(void);
void	stack_free(t_data *main_data, int state);
void	get_min(t_data *main_data, int index, int *new_stack);
void	get_max(t_data *main_data, int	*new_stack);
void	stack_index(t_data *main_data);
int		check_two_arg(char *str);
int		is_sorted(t_data *main_data);
void	move_ra(t_data *main_data);
void	move_rra(t_data *main_data);
void	move_pb(t_data *main_data);
void	move_pa(t_data *main_data);
void	move_sa(t_data *main_data);
void	small_four(t_data *main_data);
void	small_five(t_data *main_data);
void	swap_stack(t_data *main_data);

void	display_stack(t_data *main_data, int start, int end);

#endif