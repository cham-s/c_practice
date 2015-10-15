#ifndef TOOLS_H
# define TOOLS_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>

void    ft_putnbr(int nbr);
void    ft_putchar(char c);
void    ft_putstr(char *str);
void    ft_perror(char *str);
int     ft_atoi(char *str);
int     is_upper(char c);

#endif
