#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

char ft_getchar(int fd)
{
    static char buf[1000];
    static char *pufp;
    static int n = 0;

    if (n == 0)
    {
        n = read(fd, buf, sizeof buf);
        pufp = buf;
    }

    return (--n >= 0) ? (unsigned char) *pufp++ : EOF;
}

int main()
{
    int fd = open("./text", O_RDONLY);
    char c;
    while((c = ft_getchar(fd)) != EOF)
    {
        printf("%c\n", c);
    }
}