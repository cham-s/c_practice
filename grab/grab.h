#ifndef GRAB_H
# define GRAB_H

# include "../tools.h" 

typedef struct  s_line
{
    struct s_line      *next;
    int         line_nbr;
    char        *content; 
}               t_line;
#endif
