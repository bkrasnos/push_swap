/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:18:28 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/07 12:45:11 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct s_data
{
	int	max_a;
	int	max_b;
	int	flags_a;
	int	flags_b;
	int	pos_a;
	int	pos_b;
}	t_data;

typedef struct s_info
{
	int	size_b;
	int	size_a;
	int	flags;
	int	print;
}	t_info;

typedef struct s_list
{
	int	content;
	struct s_list	*next;
}	t_list;

int		solution(t_list **list_a, t_info *info);
int		free_all(t_list *list, t_info *info);
void	fast_solution(t_list **list_a, t_info *info);
int		find_min(t_list *list);
int		find_max(t_list *list, int skip);
int		find_pos(int n, t_list *list);
int		find_size(t_list *list);
void	free_list(t_list *list);
void	sa(t_list *list_a, t_list *list_b, int p);
void	sb(t_list *list_a, t_list *list_b, int p);
void	ss(t_list *list_a, t_list *list_b, int p);
void	pa(t_list **list_a, t_list **list_b, int p);
void	pb(t_list **list_a, t_list **list_b, int p);
void	ra(t_list **list_a, t_list **list_b, int p);
void	rb(t_list **list_a, t_list **list_b, int p);
void	rr(t_list **list_a, t_list **list_b, int p);
void	rra(t_list **list_a, t_list **list_b, int p);
void	rrb(t_list **list_a, t_list **list_b, int p);
void	rrr(t_list **list_a, t_list **list_b, int p);
void	print_list(t_list *list);
int		middle(t_list *list_b, int size);
void	add_link(t_list **list, int n);
t_list	*create_list(int ac, char **av, t_info **info);

#endif