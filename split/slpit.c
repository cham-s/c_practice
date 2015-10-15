#include "../tools.h"
int     size_to_allocate(char *str)
{
    int i;
    int s;

    i = 0;
    s = 0;
    if (str[i] == '\0')
        return (0);
    while (str[i] == ' ')
        i++;

    while (str[i])
    {
        if (str[i] != ' ' &&  (str[i + 1] == '\0' || str[i + 1] == ' '))
            s++;
        i++;
    }
    return (s);
}

int     *size_word(char *str)
{
    int sw;
    int i;
    int j;
    int *t;
    int s;

    j = 0;
    s = size_to_allocate(str); 
    if (s)
    {
        t = malloc(sizeof(int) * i);
        if (t)
        {
            i = 0;
            while (str[i])
            {
                while(str[i] == ' ')
                    i++;
                sw = 0;
                while (str[i] != ' ' && str[i] != '\0')
                {
                    sw++;
                    i++;
                }
                if (str[i] == ' ' ||  str[i] == '\0')
                {
                    t[j] = sw;
                    j++;
                }
            }
            return (t);
        }
    }
    return (NULL);
}

char    **init_split(char *str)
{
    char **ret;
    int *size_tab;
    int size;
    int i;
    int j;

    i = 0;
    size = size_to_allocate(str);
    size_tab = size_word(str); 
    ret = (char **)malloc(sizeof(char *) * size);
    if (ret)
    {
        while (i < size)
        {
            ret[i] = (char *)malloc(sizeof(char) * size_tab[i] + 1);
            if (ret[i])
            {
                j = 0;
                while (j < size_tab[i])
                {
                    ret[i][j] = 'a';
                    j++;
                }
                ret[i][j] = '\0';
                i++;
            }
            else
                return (NULL);
        }
        free(size_tab);
        return (ret);
    }
    return (NULL);
}

char    **ft_split(char *str, char **sp_words)
{
    int i;
    int j;
    int sr;

    i = 0;
    j = 0;
    sr = 0;
    if (sp_words)
    {
        while (str[sr])
        {
            j = 0;
            while(str[sr] == ' ')
                sr++;
            while (str[sr] != ' ' && str[sr] != '\0')
            {
                sp_words[i][j] = str[sr];
                j++;
                sr++;
            }
            i++;
        }
        return (sp_words);
    }
    return (NULL);
}

void    deallocate_mem(char *str, char **s)
{
    int size;
    int i;
    int j;

    i = 0;
    size = size_to_allocate(str);
    while (i < size)
        free(s[i]);
    free(s);
}

int     main(int ac, char **av)
{
    if (ac != 2)
    {
        ft_perror("usage: \n./split <string to split>\n");
        return (1);
    }
    int i = 0;
    int j = 0;
    int size;
    char **split;

    size = size_to_allocate(av[1]);
    split = ft_split(av[1], init_split(av[1]));
    while (i < size)
    {
        ft_putstr(split[i]);
        ft_putchar('\n');
        i++;
    }
    return (0);
}
