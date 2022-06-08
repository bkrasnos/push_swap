/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkrasnos <bkrasnos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:42:03 by bkrasnos          #+#    #+#             */
/*   Updated: 2022/06/07 12:52:08 by bkrasnos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 42

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

size_t	ft_strlen(char *s);
char	*get_next_line(int fd);
char	*ft_new_str(char *str);
char	*ft_read_str(int fd, char *str);
char	*ft_strchr(char *s, int c);
char	*ft_get_line(char *str);
char	*ft_strjoin(char *str, char *buff);

#endif