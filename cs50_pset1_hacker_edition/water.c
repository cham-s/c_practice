#include "../tools.h"
#define O_PM 192
#define O_PB 16

int     bottles_used(int minutes)
{
    return (O_PM * minutes) / O_PB;
}

int main (int argc, char **argv)
{
    if (argc != 2) 
    {
        ft_perror("usage: ./water <minutes spent on shower>\n");
        return (1);
    }
    else
    {
        if (ft_atoi(argv[1]) < 0)
        {
            ft_perror("please enter a positive number\n");
            return (1);
        }
        ft_putstr("bottle used: ");
        ft_putnbr(bottles_used(ft_atoi(argv[1])));
        ft_putchar('\n');
        return (0);
    }
}
