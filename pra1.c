#include <stdio.h>

typedef struct s_line
{
    char *string;
    size_t length;
    size_t capacity;
} t_line;

int ft_putc(t_line *line, char c)
{
    char *new_string;
    if (line->length + 1 > line->capacity)
    {
        new_string = (char *)malloc(sizeof(char) * (line->length + 1) * 2);
        if (!new_string)
            return(0);
        ft_memcpy(new_string, line->string, line->length);
        free(line->string);
        line->string = new_string;
        line->capacity = (line->length + 1) * 2;
    }
    line->string[line->length] = c;
    line->length++;
    return(1);
}

int main()
{
    t_line *line;
    char c;
    c = 'a';//readが読み込んだ文字を取り出す。

    line->string = NULL;
    line->length = 0;
    line->capacity = 1000;

    while(ft_putc(line, c))
        write(1, &c, 1);
    return(0);
}