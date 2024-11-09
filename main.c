#include "get_next_line.h"

void    ft_putstr(char *str)
{
    int i;

    if (str == NULL)
        ft_putstr("{null}");
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
    char *s;
    
    i = open("file.txt", O_RDONLY);
    while (j < 15)
    {
        s = get_next_line(i);
        ft_putstr(s);
        free(s);
        j++;
    }
}
