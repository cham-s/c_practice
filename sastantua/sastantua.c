#include "../tools.h" 

/*temporaty solution maximum size is 6 for now*/
int     spaces(int size)
{
    if (size == 1)
        return (3);
    if (size == 2)
        return (9);
    if (size == 3)
        return (16);
    if (size == 4)
        return (25);
    if (size == 5)
        return (35);
    if (size == 6)
        return (46);
    else
        return (0);
}

void sastantua(int size)
{
    int spc;
    int str;
    int br;
    int lines;
    int i;
    int j;
    int k;
    int s;

    i = 0;
    j = 0;
    k = 0;
    s = size;
    lines = 3;
    spc = spaces(size);
    str = 1;
    while (size > 0)
    {
        while (i < lines)
        {
            while (k < spc)
            {
                ft_putchar(' ');
                k++;
            }
            ft_putchar('/');
            while (j < str)
            {
                if (size == 1 && i > 1)
                {
                    if (s == 1)
                    {
                        if (j == 2)
                        {
                            ft_putchar('|');
                        }
                        else
                        {
                            ft_putchar('*');
                        }
                    }
                    if (s <= 4 && s > 1)
                    {
                        int mid = ((str - 4) / 2 );
                        int pt = mid + 3;
                        if (j > mid && j <= pt)
                        {
                            ft_putchar('|');
                        }
                        else
                        {
                            ft_putchar('*');
                        }
                    }
                    else if (s > 4)
                    {
                        int mid = ((str - 6) / 2 );
                        int pt = mid + 5;
                        if (j > mid && j <= pt)
                        {
                            if (i == s - 1 && j == mid + 4)
                                ft_putchar('$');
                            else
                                ft_putchar('|');
                        }
                        else
                        {
                            ft_putchar('*');
                        }
                    }
                }
                else
                {
                    ft_putchar('*');
                }
                j++;
            }
            ft_putchar('\\');
            ft_putchar('\n');
            str += 2;
            spc--;
            j = 0;
            k = 0;
            i++;
        }
        i = 0;
        if (s == (spc - 1) || s == size)
        {
            spc -= 2;
            str += 4;
        }
        else
        {
            spc -= 3;
            str += 6;
        }
        lines++;
        size--;
    }
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        ft_perror("usage:\n ./sastantua <size>\n");
        return (1);
    }
    else
    {
        if (ft_atoi(argv[1]) < 1 )
        {
            ft_perror("enter size greater than 0\n");
        }
        if (ft_atoi(argv[1]) > 6 )
        {
            ft_perror("size max is 6\n");
        }
        else
        {
            sastantua(ft_atoi(argv[1]));
            return (0);
        }
    }
}
