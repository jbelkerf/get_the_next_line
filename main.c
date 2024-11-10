#include "get_next_line.h"

void    ft_putstr(char *str)
{
    int i;

    if (str == NULL)
        ft_putstr("ghjk");
    i = 0;
    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int main()
{
    int i;
    int j = 0;
    
    i = open("multiple_nl.txt", O_RDONLY);
    while (j < 10)
    {
        ft_putstr(get_next_line(i));
       // write(1, "\n", 1);
        j++;
    }
}
