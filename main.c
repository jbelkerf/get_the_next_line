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
#include <fcntl.h>
#include <stdio.h>
int main()
{
    int i;
    int j = 0;
    //int c;
    
    i = open("file.txt", O_RDONLY);
    while (j < 15)
    {
         //c = j + '0' + 1;
             //  write(1, , 1);
        printf("%s",get_next_line(i));
        j++;
    }
    while (1)
    {}
}
