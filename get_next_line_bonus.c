/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnomura <rnomura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 13:35:19 by rnomura           #+#    #+#             */
/*   Updated: 2024/06/02 13:55:54 by rnomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	ft_getc(int fd)
{
	static t_buffinfo	buffinfo[OPEN_MAX];

	if (buffinfo[fd].read_byte == 0)
	{
		buffinfo[fd].read_byte = read(fd, buffinfo[fd].buff, BUFFER_SIZE);
		if (buffinfo[fd].read_byte < 0)
		{
			buffinfo[fd].read_byte = 0;
			return (-2);
		}
		buffinfo[fd].buffptr = buffinfo[fd].buff;
	}
	if (--buffinfo[fd].read_byte >= 0)
		return (*buffinfo[fd].buffptr++);
	buffinfo[fd].read_byte = 0;
	return (EOF);
}

int	ft_putc(t_line *line, char c)
{
	char	*new_string;

	if (line->length + 1 >= line->capacity)
	{
		line->capacity = (line->length + 1) * 2;
		new_string = (char *)malloc(sizeof(char) * line->capacity);
		if (!new_string)
			return (0);
		ft_memcpy(new_string, line->string, line->length);
		free(line->string);
		line->string = new_string;
	}
	line->string[line->length++] = c;
	return (1);
}

char	*get_next_line(int fd)
{
	char	c;
	t_line	line;

	if (fd < 0)
		return (NULL);
	line.length = 0;
	line.capacity = 0;
	line.string = NULL;
	while (1)
	{
		c = ft_getc(fd);
		if (c == -2)
			return (free(line.string), NULL);
		if (c == EOF)
			break ;
		if (ft_putc(&line, c) == 0)
			return (free(line.string), NULL);
		if (c == '\n')
			break ;
	}
	if (line.length > 0 && ft_putc(&line, '\0') == 0)
		return (free(line.string), NULL);
	return (line.string);
}
