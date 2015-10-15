#include "../tools.h"

char    low_to_up(char c)
{
    int d = (c % 'a') + 'A';
    return (d);
}

int     main(int argc, char **argv)
{
    int i;
    if (argc != 2)
    {
        ft_perror("usage: ./initials <full name in quotes\"Don Vito\">\n");
        return (1);
    }
    i = 0;
    while (argv[1][i] == ' ')
        i++;
    while (argv[1][i])
    {
        if (i == 0 || (argv[1][i] != ' ' && argv[1][i - 1] == ' ')) 
        {
            if (is_upper(argv[1][i]))
            {
                ft_putchar(argv[1][i]);
            }
            else
            {
                ft_putchar(low_to_up(argv[1][i]));
            }
        }
        i++;
    }
    ft_putchar('\n');
    return (0);
}
