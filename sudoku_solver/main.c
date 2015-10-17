#include "../tools.h"
#define ROW 9 
#define COL 9 
#define BLK_LIMIT 3

int     **init_grid()
{
    int **grid;
    int i;
    int j;

    i = 0;
    grid = (int **)malloc(sizeof(int *) * COL);
    if (grid)
    {
        while (i < COL)
        {
            grid[i] = (int *)malloc(sizeof(int) * ROW);
            if (grid[i])
            {
                j = 0;
                while (j < ROW)
                {
                    grid[i][j] = 0;
                    j++;
                }
            }
            else
                return (NULL);
            i++;
        }
        return (grid);
    }
    return (NULL);
}

void    fill_col(char *str, int *col)
{
    int i;
    
    i = 0;
    while (str[i])
    {
        if (str[i] != '.')
            col[i] = str[i] - '0';
        i++;
    }
}

void    display_grid(int **grid)
{
    int i;
    int j;

    if (grid == NULL)
    {
        ft_perror("error: empty grid\n");
        exit(1);
    }
    i = 0;
    while (i < COL)
    {
        j = 0;
        while (j < ROW)
        {
            ft_putnbr(grid[i][j]);
            if (j < ROW - 1)
                ft_putchar(' ');
            j++;
        }
        ft_putchar('\n');
        i++;
    }
}

int     is_unique(char *str, int arg_nbr)
{
    int i;
    int j;

    i = 0;
    while (str[i])
    {
        j = i + 1;
        while (str[j])
        {
            if (str[j] != '.' && str[i] != '.')
            {
                if (str[i] == str[j])
                {
                    ft_perror("doublon in the sudoku to be more precise in argument ");
                    ft_putnbr(arg_nbr);
                    ft_putchar('\n');
                    return (0);
                }
            }
            j++;
        }
        i++;
    }
    return (1);
}

int     is_args_ok(int ac, char **av)
{
    int i;
    int j;

    if (ac != 10)
    {
        ft_putstr("wrong number of arguments ");
        ft_putnbr(ac - 1);
        ft_putstr(" instead of 9\n");
        return (0);
    }
    i = 1;
    while (i <= COL)
    {
        j = 0;
        j = 0;
        if (!is_unique(av[i], i))
            return (0);
        while (av[i][j])
        {
            if ((av[i][j] < '0' || av[i][j] > '9') && 
                    av[i][j] != '.')
            {
                ft_putstr("invalid character input '");
                ft_putchar(av[i][j]);
                ft_putstr("' in argument number ");
                ft_putnbr(i);
                ft_putstr("\n");
                return (0);
            }
            j++;
        }
        if (j != ROW)
        {
            ft_putstr("the number of tile is not equal to 9 in argument ");
            ft_putnbr(i + 1);
            ft_putstr("\n");
            return (0);
        }
        i++;
    }
    return (1);
}

int     value_is_missing_on_line(int digit, int **grid, int i)
{
    int j;
    j = 0;
    while (j < COL)
    {
        if (grid[i][j] == digit)
            return (0);
        j++;
    }
    return (1);
}

int     value_is_missing_on_col(int digit, int **grid, int j)
{
    int i;
    i = 0;
    while (i < ROW)
    {
        if (grid[i][j] == digit)
            return (0);
        i++;
    }
    return (1);
}

int    value_is_missing_on_block(int digit, int **grid, int i, int j)
{
    int c_i;
    int c_j;

    c_i = i - (i % BLK_LIMIT);
    c_j = j - (j % BLK_LIMIT);
    while (i < c_i + BLK_LIMIT)
    {
        while (j < c_j + BLK_LIMIT)
        {
            if (grid[i][j] == digit)
                return (0);
            j++;
        }
        i++;
    }
    return (1);
}

int     is_valid(int **grid, int position)
{
    if (position == ROW * COL)
        return (1);

    int i;
    int j;
    int digit;

    i = position / COL;
    j = position % ROW;

    if (grid[i][j] != 0)
        return (is_valid(grid, position + 1));
    digit = 1;
    while (digit <= 9)
    {
        if (value_is_missing_on_line(digit, grid, i) &&
            value_is_missing_on_col(digit, grid, j) &&
            value_is_missing_on_block(digit, grid, i, j))
        {
            grid[i][j] = digit;
            if (is_valid(grid, position + 1))
                return (1);
        }
        digit++;
    }
    grid[i][j] = 0;
    return (0);

}

int main (int ac, char **av)
{
    if (!(is_args_ok(ac, av)))
    {
        return (1);
    }
    int i;
    int j;
    int **grid = init_grid(); 
    i = 0;
    j = 1;
    while (i < COL)
    {
        fill_col(av[j], grid[i]);
        i++;
        j++;
    }
    display_grid(grid);
    ft_putchar('\n');
    is_valid(grid, 0);
    display_grid(grid);
    free(grid);
}
