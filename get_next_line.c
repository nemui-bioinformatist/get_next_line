/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rnomura <rnomura@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 22:54:09 by rnomura           #+#    #+#             */
/*   Updated: 2024/05/26 12:33:38 by rnomura          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

typedef struct s_line
{
    char *string;
    size_t length;
    size_t capacity;
} t_line;

char ft_getc(int fd)
{
    static char buf[BUFFER_SIZE];
    static char *pufp;
    static int n = 0;

    if (n == 0)
    {
        n = read(fd, buf, sizeof buf)
        pufp = buf;
    }

    if (--n >= 0)// n = 1でstop
        return(*pufp++);
    return(EOF);
}

char putc(t_line *line, char c)
{
    char *new_string;

    if (line->length + 1 > line->capacity)
    {
    }
}

char *get_next_line(int fd)
{
    char c;
    char *result;
    t_line *line;

    line->string = NULL;
    line->length = 0;
    line->capacity = BUFFER_SIZE;
    
    while (1)
    {
        c = ft_getchar(fd);

        if (c == EOF)
            break;
        else if (c == '\n')
            break;
        ft_putc(line, c);
    }
    result = line->string;
    free(line->string);
    return (result);
}
