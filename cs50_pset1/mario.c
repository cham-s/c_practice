#include "../tools.h"

int     main(int argc, char **argv)
{
    if (argc != 2)
    {
       ft_perror("usage: ./mario <pyramide size>\n"); 
       return (1);
    }
    else 
    {
        if (ft_atoi(argv[1]) > 23 || ft_atoi(argv[1]) < 1)
        {
            ft_perror("The min is 1 and the max is 23\n");
            return (1);
        }
        int i = 0;
        int sz = ft_atoi(argv[1]); 
        int spc = sz - 1;
        int mk = 2;
        while (sz > 0)
        {
           while (i < spc) 
           {
               ft_putchar(' ');
               i++;
           }
           i = 0;
           while (i < mk)
           {
               ft_putchar('#');
               i++;
           }
           ft_putstr("  ");
           i = 0;
           while (i < mk)
           {
               ft_putchar('#');
               i++;
           }
           ft_putchar('\n');
           sz--;
           mk++;
           spc--;
           i = 0;
        }
    }
}
