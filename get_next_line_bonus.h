/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnomura <rnomura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:38:51 by rnomura           #+#    #+#             */
/*   Updated: 2024/06/02 13:41:20 by rnomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_line
{
	char	*string;
	size_t	length;
	size_t	capacity;
}			t_line;

typedef struct s_buffinfo
{
	char	buff[BUFFER_SIZE];
	char	*buffptr;
	int		read_byte;
}			t_buffinfo;

void		*ft_memcpy(void *dst, const void *src, size_t n);
char		ft_getc(int fd);
int			ft_putc(t_line *line, char c);
char		*get_next_line(int fd);

#endif // GET_NEXT_LINE_BONUS_H
