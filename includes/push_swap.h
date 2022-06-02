/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 13:18:28 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/02 16:17:03 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct	s_stack
{
	long int	num;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct	s_frame
{
	struct s_stack	*a;
	struct s_stack	*b;
	char	**argv;
	char	*line;
	char	*str;
	int		print;
	int		write;
	int		length_stack;
	int		big_rotate;
	int		big_rrotate;
	int		big_flag;
	int		small_rotate;
	int		small_rrotate;
	int		small_flag;
	int		rotate;
	long	quarter;
	long	median;
	long	three_quarters;
	long	biggest;
	long	smallest;
}	t_frame;

#endif