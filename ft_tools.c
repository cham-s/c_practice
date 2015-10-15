#include "tools.h"

int     is_upper(char c)
{
    if (c < 'A' || c > 'Z')
        return (0);
    else
        return (1);
}

void    ft_putchar(char c)
{
    write(1, &c, 1);
}
void    ft_putnbr(int nbr)
{
    if (nbr < 0)
    {
        ft_putchar('-');
        nbr = -nbr;
    }
    if (nbr > 9)
    {
        ft_putnbr(nbr / 10);
        ft_putnbr(nbr % 10);
    }
    else
        ft_putchar(nbr + '0');
}

void    ft_perror(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(2, &str[i], 1);
        i++;
    }
}

void    ft_putstr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int     ft_atoi(char *str)
{
    int i;
    int d;
    int r;

    i = 0;
    r = 0;
    d = 1;
    if (str[0] == '-')
        i++;
    while (str[i])
    {
        if (str[i] < '0' && str[i] > '9')
            return (0);
        i++;
    }
    i--;
    while (i >= 0 && str[i] != '-')
    {
        r = r + (str[i] - '0') * d;
        i--;
        d *= 10;
    }
    return ((str[0] == '-'? -r : r));
}

int     ft_strlen(char *str)
{
    int i;

    i = 0;
    while (str[i])
        i++;
    return (i);
}
