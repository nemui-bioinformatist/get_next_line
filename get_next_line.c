/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnomura <rnomura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:54:09 by rnomura           #+#    #+#             */
/*   Updated: 2024/05/29 00:17:56 by rnomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*memo_dst;
	const unsigned char	*memo_src;
	size_t				i;

	memo_dst = (unsigned char *)dst;
	memo_src = (const unsigned char *)src;
	if (dst == src)
		return (dst);
	i = 0;
	while (n--)
	{
		memo_dst[i] = memo_src[i];
		i++;
	}
	return ((void *)memo_dst);
}

char	ft_getc(int fd)
{
	static t_buffinfo	buffinfo;

	if (buffinfo.read_byte == 0)
	{
		buffinfo.read_byte = read(fd, buffinfo.buff, BUFFER_SIZE);
		if (buffinfo.read_byte < 0)
		{
			buffinfo.read_byte = 0;
			return (-2);
		}
		buffinfo.buffptr = buffinfo.buff;
	}
	if (--buffinfo.read_byte >= 0)
		return (*buffinfo.buffptr++);
	buffinfo.read_byte = 0;
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

// #include <stdio.h>

// int main()//->ft_getc
// {
//     int fd = open("./text.txt", O_RDONLY);
//     printf("%c", ft_getc(fd));
// }

// int main()//->ft_putc
// {
//     t_line line;
//     line.length = 0;
//     line.capacity = BUFFER_SIZE;
//     line.string = (char *)malloc(BUFFER_SIZE * sizeof(char) * line.capacity);

//     ft_putc(&line, 'H');
//     ft_putc(&line, 'e');
//     ft_putc(&line, 'l');
//     ft_putc(&line, 'l');
//     ft_putc(&line, 'o');

//     // 結果を表示
//     printf("Resulting string: %s\n", line.string);

//     // メモリの解放
//     free(line.string);

//     return (0);
// }

// #----------------------------main.c-----------------------------#
// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q a.out");
// }

// int main()//->get_next_line
// {
//     int fd = open("./text.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         perror("Error opening file");
//         return (1);
//     }
//     char *line;
//     while(42)
//     {
//         line = get_next_line(fd);
//         if (!line)
//             return (0);
//         printf("%s\n", line);
//         free(line);
//     }
//     close(fd);
//     return (0);
// }

// #-----------------------------------------------------------------#