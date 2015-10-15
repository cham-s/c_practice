#include "grab.h"
#define BUF_SIZE 4096 

void    str_find(char *str, char* to_find)
{
    int i;
    int j;
    int k;
    int c;
    int count;

    i = 0;
    c = 0;
    count = 1;
    while (str[i])
    {
        j = i;
        k = 0;
        while (to_find[k] == str[j])
        {
            k++;
            j++;
            if (to_find[k] == '\0')
            {
                ft_putnbr(count);
                ft_putstr(": ");
                while (str[c] != '\n' && str[c] != '\0')
                {
                   ft_putchar(str[c]); 
                   c++;
                }
                ft_putchar('\n'); 
                i = c;
                c++;
            }
        }
        if (str[i] == '\n')
        {
            c = i + 1;
            count++;
        }
        i++;
    }
}

void    from_file(char *filename, char *src)
{
    int fd;
    int ret;
    char buf[BUF_SIZE + 1];

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        ft_perror("error in open()");
        exit(1);
    }
    while ((ret = read(fd, buf, BUF_SIZE)))
    {
        buf[ret] = '\0';
        str_find(buf, src);
    }
    if (close(fd) == -1)
    {
        ft_perror("error in close()");
        exit(1);
    }
}

void from_stdin(char *src)
{
    // TODO: get data from stdin
}

int main(int ac, char **av)
{
    if (ac != 3)
    {
        ft_perror("Error:        usage ./grab <word> <file>");
        return (1);
    }
    from_file(av[2], av[1]);
}
