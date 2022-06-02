/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:18:28 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/02 17:19:22 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../ft_printf/includes/ft_printf.h"
# include "../get_next_line/get_next_line.h"

typedef struct s_data
{
	int				max_a;
	int				max_b;
	int				flags_a;
	int				flags_b;
	int				pos_a;
	int				pos_b;
}	t_data;

typedef struct s_info
{
	int				pivot;
	int				size_b;
	int				size_a;
	int				flags;
	int				vis;
}	t_info;

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	t_list;

#endif